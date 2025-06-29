// librarydatabase.h
#ifndef LIBRARYDATABASE_H
#define LIBRARYDATABASE_H

#include "datastorage.h"
#include <QString>

class LibraryDatabase {
public:
    // 单例模式获取数据库实例
    static LibraryDatabase& getInstance() {
        static LibraryDatabase instance;
        return instance;
    }

    // 禁止拷贝
    LibraryDatabase(const LibraryDatabase&) = delete;
    LibraryDatabase& operator=(const LibraryDatabase&) = delete;

    // 加载数据
    bool loadData();

    // 保存数据
    bool saveData() const;

    // 获取数据
    std::vector<reader>& getReaders() { return readers; }
    std::vector<Book>& getBook() { return books; }
    std::vector<reader> readers;
    std::vector<Book> books;
    int total=books.size();
    void deletebook(QString name){
        for(auto is=books.begin();is<books.end();++is){
            std::string Name = name.toUtf8().toStdString();
            if(Name==is->getName()){
                books.erase(is);
            }
        }
    }
private:
    // 私有构造函数
    LibraryDatabase() = default;
// 文件名常量



    const std::string READERS_FILE = "readers.txt";
    const std::string BOOK_FILE = "books.txt";
};

#endif // LIBRARYDATABASE_H
