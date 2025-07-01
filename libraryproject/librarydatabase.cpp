// librarydatabase.cpp
#include "librarydatabase.h"
#include <QDebug>
#include "Reader.h"
#include "Reader.h"
#include <QDate>

bool LibraryDatabase::loadData() {

    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    readers.clear();
    books.clear();

    // 开始事务
    if (!db.transaction()) {
        qDebug() << "Begin transaction failed:" << db.lastError().text();
        return false;
    }

    // 加载读者数据
    QSqlQuery readerQuery(db);
    if (!readerQuery.exec("SELECT * FROM readers")) {
        qDebug() << "Reader query execution failed:" << readerQuery.lastError().text();
        return false;
    }
    while (readerQuery.next()) {
        QVariant nameVariant = readerQuery.value("name");
        QVariant passwordVariant = readerQuery.value("password");

        if (!nameVariant.isValid() || nameVariant.toString().isNull() ||
            !passwordVariant.isValid() || passwordVariant.toString().isNull()) {
            qDebug() << "Invalid or null name/password field";
            continue; // 跳过无效条目
        }

        std::string name = nameVariant.toString().toStdString();
        std::string password = passwordVariant.toString().toStdString();
        bool is_vip = readerQuery.value("is_vip").toBool();
        int debt = readerQuery.value("debt").toInt();
        bool locked = readerQuery.value("locked").toBool();
        int valid = readerQuery.value("valid").toInt();

        std::vector<std::string> borrowedBooks;
        std::vector<QDate> borrowDates;
        std::vector<QDate> deadlines;
        QSqlQuery borrowedQuery(db);
        borrowedQuery.prepare("SELECT book_id, borrowtime, deadline FROM borrowed_books WHERE reader_name = :name");
        borrowedQuery.bindValue(":name", QString::fromStdString(name));

        if (borrowedQuery.exec()) {
            while (borrowedQuery.next()) {
                borrowedBooks.push_back(borrowedQuery.value("book_id").toString().toStdString());
                borrowDates.push_back(QDate::fromString(borrowedQuery.value("borrowtime").toString(), Qt::ISODate));
                deadlines.push_back(QDate::fromString(borrowedQuery.value("deadline").toString(), Qt::ISODate));
            }
        }

        readers.emplace_back(name, password, borrowedBooks, valid);
        readers.back().setDebt(debt);
        if (locked) readers.back().setLocked();
    }

    // 加载书籍数据
    QSqlQuery bookQuery(db);
    if (!bookQuery.exec("SELECT * FROM books")) {
        qDebug() << "Book query execution failed:" << bookQuery.lastError().text();
        db.rollback();
        return false;
    }
    while (bookQuery.next()) {
        std::string name = bookQuery.value("name").toString().toStdString();
        std::string author = bookQuery.value("author").toString().toStdString();
        std::string publisher = bookQuery.value("publisher").toString().toStdString();
        std::string isbn = bookQuery.value("isbn").toString().toStdString();
        std::string type = bookQuery.value("type").toString().toStdString();

        books.emplace_back(name, author, publisher, isbn, type);
    }
    if (!db.commit()) {
        qDebug() << "Commit failed:" << db.lastError().text();
        db.rollback();
        return false;
    }

    return true;
}

bool LibraryDatabase::saveData()  {
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    // 开始事务
    if (!db.transaction()) {
        qDebug() << "Begin transaction failed:" << db.lastError().text();
        return false;
    }
    // 保存读者数据
    QSqlQuery deleteReadersQuery(db);
    if (!deleteReadersQuery.exec("DELETE FROM readers")) {
        qDebug() << "Failed to delete readers:" << deleteReadersQuery.lastError().text();
        const_cast<QSqlDatabase&>(db).rollback();
        return false;
    }

    QSqlQuery deleteBorrowedQuery(db);
    if (!deleteBorrowedQuery.exec("DELETE FROM borrowed_books")) {
        qDebug() << "Failed to delete borrowed books:" << deleteBorrowedQuery.lastError().text();
        const_cast<QSqlDatabase&>(db).rollback();
        return false;
    }
    for (const auto& reader : readers) {
        QSqlQuery insertReaderQuery(db);
        insertReaderQuery.prepare("INSERT INTO readers (name, password, is_vip, debt, locked, valid) "
                                  "VALUES (:name, :password, :is_vip, :debt, :locked, :valid)");
        insertReaderQuery.bindValue(":is_vip", reader.isVip());
        insertReaderQuery.bindValue(":name", QString::fromStdString(reader.getName()));
        insertReaderQuery.bindValue(":password", QString::fromStdString(reader.getPassword()));
        insertReaderQuery.bindValue(":debt", reader.getDebt());
        insertReaderQuery.bindValue(":locked", reader.isLocked());
        insertReaderQuery.bindValue(":valid", reader.getvalid());
        if (!insertReaderQuery.exec()) {
            qDebug() << "Failed to insert reader:" << insertReaderQuery.lastError().text();
            return false;
        }

        const auto& borrowedBooks = reader.getBorrowedBooks();
        const auto& borrowDates = reader.getBorrowDates();
        const auto& deadlines = reader.getDeadlines();
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            QSqlQuery insertBorrowedQuery(db);
            insertBorrowedQuery.prepare("INSERT INTO borrowed_books (reader_name, book_id, borrowtime, deadline)"
                                        " VALUES (:name, :book_id, :borrowtime, :deadline)");
            insertBorrowedQuery.bindValue(":name", QString::fromStdString(reader.getName()));
            //insertBorrowedQuery.bindValue(":book_id", QString::fromStdString(borrowedBooks[i]));
            std::string bookId = "";
            for (const auto& book : books) {
                if (book.getName() == borrowedBooks[i]) {
                    bookId = book.getisbn();
                    break;
                }
            }
            if (bookId.empty()) {
                qDebug() << "Book not found:" << QString::fromStdString(borrowedBooks[i]);
                continue; // 跳过无效记录
            }
            insertBorrowedQuery.bindValue(":book_id", QString::fromStdString(bookId));
            insertBorrowedQuery.bindValue(":borrowtime", borrowDates[i].toString(Qt::ISODate));
            insertBorrowedQuery.bindValue(":deadline", deadlines[i].toString(Qt::ISODate));
            if (!insertBorrowedQuery.exec()) {
                qDebug() << "Failed to insert borrowed book:"
                         << insertBorrowedQuery.lastError().text()
                         << "\nQuery:" << insertBorrowedQuery.lastQuery();
                db.rollback();
                return false;
            }
        }
    }

    // 保存书籍数据
    QSqlQuery deleteBooksQuery("DELETE FROM books", db);
    for (const auto& book : books) {
        QSqlQuery insertBookQuery(db);
        insertBookQuery.prepare("INSERT INTO books (isbn, name, author, publisher, type) "
                                "VALUES (:isbn, :name, :author, :publisher, :type)");
        insertBookQuery.bindValue(":isbn", QString::fromStdString(book.getisbn()));
        insertBookQuery.bindValue(":name", QString::fromStdString(book.getName()));
        insertBookQuery.bindValue(":author", QString::fromStdString(book.getAuthor()));
        insertBookQuery.bindValue(":publisher", QString::fromStdString(book.getPublisher()));
        insertBookQuery.bindValue(":type", QString::fromStdString(book.getType()));
        if (!insertBookQuery.exec()) {
            qDebug() << "Failed to insert book:" << insertBookQuery.lastError().text();
            db.rollback(); // 添加回滚
            return false;
        }
    }
    if (!db.commit()) {
        qDebug() << "Commit failed:" << db.lastError().text();
        db.rollback();
        return false;
    }

    return true;
}

LibraryDatabase::~LibraryDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}
