// datastorage.cpp
#include "datastorage.h"

bool DataStorage::saveReaders(const std::vector<reader>& readers, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }

    for (const auto& reader : readers) {
        file << reader.getName() << ","
             << reader.getPassword() << ","
             << reader.getDebt() << ","
             << reader.isLocked() << ","
             << reader.getvalid() << "\n";

        // 保存借阅的书籍
        const auto& borrowedBooks = reader.getBorrowedBooks();
        file << borrowedBooks.size() << "\n";
        for (const auto& bookId : borrowedBooks) {
            file << bookId << "\n";
        }
    }

    return true;
}

bool DataStorage::loadReaders(std::vector<reader>& readers, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // 文件不存在可能是首次运行，返回true表示成功
        std::cout << "文件不存在，将创建新数据库: " << filename << std::endl;
        return true;
    }

    readers.clear();
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, password;
        int debt, locked, valid;

        if (std::getline(iss, name, ',') &&
            std::getline(iss, password, ',') &&
            (iss >> debt) && iss.ignore() &&
            (iss >> locked) && iss.ignore() &&
            (iss >> valid)) {

            // 读取借阅的书籍
            std::getline(file, line);
            int bookCount = std::stoi(line);

            std::vector<std::string> borrowedBooks;
            for (int i = 0; i < bookCount; ++i) {
                std::getline(file, line);
                borrowedBooks.push_back(line);
            }

            readers.emplace_back(name, password, borrowedBooks, valid);
            readers.back().setDebt(debt);
            if (locked) readers.back().setLocked();
        }
    }

    return true;
}
