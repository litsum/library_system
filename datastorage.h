// datastorage.h
#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <string>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "book.h"
#include <sstream>

class DataStorage {
public:
    // 保存读者数据到文件
    static bool saveReaders(const std::vector<reader>& readers, const std::string& filename);

    // 从文件加载读者数据
    static bool loadReaders(std::vector<reader>& readers, const std::string& filename);

    // 保存书籍数据到文件 (模板函数支持不同类型的书籍)
    template<typename BookType>
    static bool saveBooks(const std::vector<BookType>& books, const std::string& filename);

    // 从文件加载书籍数据
    template<typename BookType>
    static bool loadBooks(std::vector<BookType>& books, const std::string& filename);
};

// 模板函数实现 (通常放在头文件中)
template<typename BookType>
bool DataStorage::saveBooks(const std::vector<BookType>& books, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }

    for (const auto& book : books) {
        file << book.getName() << ","
             << book.getAuthor() << ","
             << book.getPublisher() << ","
             << book.getISBN() << "\n";
    }

    return true;
}

template<typename BookType>
bool DataStorage::loadBooks(std::vector<BookType>& books, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }

    books.clear();
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, author, publisher, isbn;

        if (std::getline(iss, name, ',') &&
            std::getline(iss, author, ',') &&
            std::getline(iss, publisher, ',') &&
            std::getline(iss, isbn)) {
            books.emplace_back(name, author, publisher,isbn);
        }
    }

    return true;
}

#endif // DATASTORAGE_H
