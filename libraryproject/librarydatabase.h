// librarydatabase.h
#ifndef LIBRARYDATABASE_H
#define LIBRARYDATABASE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <vector>
#include "Reader.h"
#include "book.h"

class LibraryDatabase {
public:
    // 单例模式获取数据库实例
    static LibraryDatabase& getInstance() {
        static LibraryDatabase instance;
        return instance;
    }
    void setDatabase(const QSqlDatabase& database) {
        db = database;
    }
    QSqlDatabase& getDatabase() { return db; } // 添加这个方法

    // 禁止拷贝
    LibraryDatabase(const LibraryDatabase&) = delete;
    LibraryDatabase& operator=(const LibraryDatabase&) = delete;

    // 加载数据
    bool loadData();

    // 保存数据
    bool saveData();

    // 获取数据
    std::vector<reader>& getReaders() { return readers; }
    std::vector<Book>& getBook() { return books; }
    std::vector<reader> readers;
    std::vector<Book> books;
    int total=books.size();
    bool deletebook(QString name){
        std::string searchName = name.toStdString();
        auto it = std::remove_if(books.begin(), books.end(),
                                 [&](const Book& b) { return b.getName() == searchName; });

        if (it != books.end()) {
            books.erase(it, books.end());
            return true;
        }
        return false;
    }
private:
    // 私有构造函数
    LibraryDatabase() = default;
    ~LibraryDatabase();
    QSqlDatabase db;
// 文件名常量



    const std::string READERS_FILE = "readers.txt";
    const std::string BOOK_FILE = "books.txt";
};

#endif // LIBRARYDATABASE_H
