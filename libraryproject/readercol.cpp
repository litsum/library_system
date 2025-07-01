#include "readercol.h"
#include "ui_readercol.h"
#include "book.h"
#include "database.h"
#include <QMessageBox>
#include <QMenu>
#include <QStandardItem>
#include <QHeaderView>
#include "find.h"
#include <QDate>

readercol::readercol(QWidget *parent)
    : QDialog(parent), ui(new Ui::readercol)
{
    ui->setupUi(this);

    // 初始化模型
    model = new QStringListModel(this);
    _model = new QStandardItemModel(0, 5, this); // 确保正确初始化

    // 设置表头
    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社", "状态"});

    // 获取当前登录的读者
    currentReader = nullptr;
    for(auto &reader : db.readers) {
        if(reader.isLocked()) { // 假设 isLocked 表示已登录
            currentReader = &reader;
            break;
        }
    }
    if(!currentReader) {
        QMessageBox::warning(this, "错误", "未找到登录的读者!");
        return;
    }

    // 显示当前读者的借阅列表
    model->setStringList(currentReader->borrowbooklist());
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑

    // 加载所有图书到表格
    loadAllBooks();
    ui->comboBox->addItem("ISBN", 0);
    ui->comboBox->addItem("书名", 1);
    ui->comboBox->addItem("作者", 2);
    ui->comboBox->addItem("出版社", 3);

    // 设置表格属性
    BookSearchProxyModel *proxyModel = new BookSearchProxyModel(this);
    proxyModel->setSourceModel(_model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->lineEdit, &QLineEdit::textChanged,
            [proxyModel](const QString &text) {
                proxyModel->setSearchPrefix(text);
            });
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [proxyModel](int index) {
                proxyModel->setSearchColumn(index);
            });
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,
            &readercol::textchange);

    // 右键菜单 - 借书功能
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    // connect(ui->tableView, &QTableView::customContextMenuRequested,
    //         this, &readercol::showContextMenu);
    connect(ui->tableView, &QTableView::customContextMenuRequested, [this, proxyModel](const QPoint &pos){
        QModelIndex index = ui->tableView->indexAt(pos);
        QMenu menu;
        QAction *borrowAction = menu.addAction("添加图书");
        if (borrowAction == menu.exec(ui->tableView->viewport()->mapToGlobal(pos))) {

            if (index.isValid()) {
                // 映射到源模型索引
                QModelIndex sourceIndex = proxyModel->mapToSource(index);
                if (sourceIndex.isValid()) {
                    QString name = _model->item(sourceIndex.row(), 1)->text();
                    std::string Name = name.toUtf8().toStdString();
                    bool alreadyBorrowed = false;
                    for(const auto &borrowed : currentReader->getBorrowedBooks()) {
                        if(borrowed == Name) {
                            alreadyBorrowed = true;
                            break;
                        }
                    }
                    borrowAction->setEnabled(!alreadyBorrowed);
                    auto bookIt = std::find_if(db.books.begin(), db.books.end(),
                                               [&](const Book& b) { return b.getName() == Name; });

                    if(bookIt != db.books.end()) {
                        if(bookIt->isAvailable()) {
                            QDate borrowDate = QDate::currentDate();
                            QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
                            currentReader->borrowBook(Name, borrowDate, deadlineDate);
                            bookIt->setAvailable(false);
                            QMessageBox::information(this, "成功", "借阅成功!");
                            refreshBookList();
                            loadAllBooks(); // 刷新图书状态
                        } else {
                            QMessageBox::warning(this, "失败", "图书已被借出!");
                        }
                }
            }
        }
    }
    });
    // 初始化还书功能右键菜单
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, &QListView::customContextMenuRequested,
            this, &readercol::showReturnMenu);

}

readercol::~readercol()
{
    delete ui;
}

void readercol::loadAllBooks()
{
    _model->removeRows(0, _model->rowCount());
    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社", "状态", "借阅日期", "到期日期"});

    int row = 0;
    for(const auto &book : db.books) {
        QList<QStandardItem*> rowItems;

        // ISBN
        QString isbn = QString::fromStdString(book.getisbn());
        QStandardItem *isbnItem = new QStandardItem(isbn);
        isbnItem->setEditable(false);

        // 书名
        QString name = QString::fromStdString(book.getName());
        QStandardItem *nameItem = new QStandardItem(name);

        // 作者
        QString author = QString::fromStdString(book.getAuthor());
        QStandardItem *authorItem = new QStandardItem(author);

        // 出版社
        QString publisher = QString::fromStdString(book.getPublisher());
        QStandardItem *publisherItem = new QStandardItem(publisher);

        // 状态
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(book.isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(book.isAvailable() ? "可借阅" : "已借出");
        statusItem->setEditable(false);
        // 添加借阅日期和到期日期
        QStandardItem *borrowDateItem = new QStandardItem();
        QStandardItem *deadlineItem = new QStandardItem();

        // 查找借阅记录
        for (size_t i = 0; i < db.readers.size(); i++) {
            const auto& borrowedBooks = db.readers[i].getBorrowedBooks();
            auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book.getisbn());

            if (it != borrowedBooks.end()) {
                size_t index = std::distance(borrowedBooks.begin(), it);
                borrowDateItem->setText(db.readers[i].getBorrowDates()[index].toString("yyyy-MM-dd"));
                deadlineItem->setText(db.readers[i].getDeadlines()[index].toString("yyyy-MM-dd"));

                // 检查是否逾期
                if (QDate::currentDate() > db.readers[i].getDeadlines()[index]) {
                    deadlineItem->setForeground(QBrush(Qt::red));
                }
                break;
            }
        }

        rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem << borrowDateItem << deadlineItem;
        _model->appendRow(rowItems);
        row++;
    }
}

void readercol::showContextMenu(const QPoint &pos)
{
    if(!currentReader) return;

    QModelIndex index = ui->tableView->indexAt(pos);
    if(!index.isValid()) return;

    QString bookName = _model->index(index.row(), 1).data().toString();
    std::string bookNameStr = bookName.toStdString();

    // 检查是否已借阅
    bool alreadyBorrowed = false;
    for(const auto &borrowed : currentReader->getBorrowedBooks()) {
        if(borrowed == bookNameStr) {
            alreadyBorrowed = true;
            break;
        }
    }

    QMenu menu;
    QAction *borrowAction = menu.addAction("借阅图书");
    borrowAction->setEnabled(!alreadyBorrowed);

    if(menu.exec(ui->tableView->viewport()->mapToGlobal(pos))) {
        // 查找图书
        auto bookIt = std::find_if(db.books.begin(), db.books.end(),
            [&](const Book& b) { return b.getName() == bookNameStr; });

        if(bookIt != db.books.end()) {
            if(bookIt->isAvailable()) {
                QDate borrowDate = QDate::currentDate();
                QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
                currentReader->borrowBook(bookNameStr, borrowDate, deadlineDate);
                bookIt->setAvailable(false);
                QMessageBox::information(this, "成功", "借阅成功!");
                refreshBookList();
                loadAllBooks(); // 刷新图书状态
            } else {
                QMessageBox::warning(this, "失败", "图书已被借出!");
            }
        }
    }
}

void readercol::showReturnMenu(const QPoint &pos)
{
    if(!currentReader) return;

    QModelIndex index = ui->listView->indexAt(pos);
    if(!index.isValid()) return;

    QString bookName = model->data(index).toString();
    std::string bookNameStr = bookName.toStdString();

    QMenu menu;
    menu.addAction("归还图书");

    if(menu.exec(ui->listView->viewport()->mapToGlobal(pos))) {
        for(auto bookIt=db.books.begin();bookIt!=db.books.end();++bookIt)
        if(bookIt->getName()==bookNameStr) {
            currentReader->returnBook(bookNameStr);
            bookIt->setAvailable(true);
            QMessageBox::information(this, "成功", "归还成功!");
            currentReader->deletelist(bookName);
            refreshBookList();
            loadAllBooks(); // 刷新图书状态
            break;
        }
    }
}


void readercol::refreshBookList()
{
    if (!currentReader) return;

    model->removeRows(0, model->rowCount());
    QStringList bookList;

    for (size_t i = 0; i < currentReader->getBorrowedBooks().size(); i++) {
        QString bookInfo = QString("%1 (借于: %2, 到期: %3)")
                               .arg(QString::fromStdString(currentReader->getBorrowedBooks()[i]))
                               .arg(currentReader->getBorrowDates()[i].toString("yyyy-MM-dd"))
                               .arg(currentReader->getDeadlines()[i].toString("yyyy-MM-dd"));

        // 高亮显示逾期书籍
        if (QDate::currentDate() > currentReader->getDeadlines()[i]) {
            bookInfo = "<font color='red'>" + bookInfo + "</font>";
        }

        bookList.append(bookInfo);
    }
    model->setStringList(bookList);
}

void readercol::textchange(int index){
    switch (index) {
    case 0:
        ui->lineEdit->setPlaceholderText("ISBN:");
        break;
    case 1:
        ui->lineEdit->setPlaceholderText("书名:");
        break;
    case 2:
        ui->lineEdit->setPlaceholderText("作者:");
        break;
    case 3:
        ui->lineEdit->setPlaceholderText("出版社:");
        break;
    default:
        break;
    }
}

void readercol::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit_2->text();
    std::string content = str.toUtf8().toStdString();

}

// readercol.cpp
void readercol::borrowBook(const std::string& bookId, const QDate& borrowDate, const QDate& deadline) {
    if (!currentReader) return;
    /*QDate deadlineDate;
    if (currentReader->isVip()) {
        deadlineDate = borrowDate.addDays(30); // VIP借30天
    } else {
        deadlineDate = borrowDate.addDays(10); // 非VIP借10天
    }*/
    QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
    // 更新内存对象
    currentReader->borrowBook(bookId, borrowDate, deadlineDate);

    // 更新书籍状态
    auto bookIt = std::find_if(db.books.begin(), db.books.end(),
                               [&](const Book& b) { return b.getisbn() == bookId; });

    if (bookIt != db.books.end()) {
        bookIt->setAvailable(false);
    }

    // 刷新界面
    refreshBookList();
    loadAllBooks();

    // 保存到数据库
    QSqlQuery query;
    query.prepare(
        "INSERT INTO borrowed_books (reader_name, book_id, borrowtime, deadline) "
        "VALUES (:name, :book_id, :borrowtime, :deadline)");
    query.bindValue(":name", QString::fromStdString(currentReader->getName()));
    query.bindValue(":book_id", QString::fromStdString(bookId));
    query.bindValue(":borrowtime", borrowDate.toString(Qt::ISODate));
    query.bindValue(":deadline", deadlineDate.toString(Qt::ISODate));
    if (!query.exec()) {
        qDebug() << "Borrow book insert error:" << query.lastError().text();
    }
    // 更新内存对象
}
