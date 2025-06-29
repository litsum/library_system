// librarydatabase.cpp
#include "librarydatabase.h"

bool LibraryDatabase::loadData() {
    bool success = true;

    // 加载读者数据
    success &= DataStorage::loadReaders(readers, READERS_FILE);

    // 加载书籍数据
    success &= DataStorage::loadBooks(books, BOOK_FILE);

    return success;
}

bool LibraryDatabase::saveData() const {
    bool success = true;

    // 保存读者数据
    success &= DataStorage::saveReaders(readers, READERS_FILE);

    // 保存书籍数据
    success &= DataStorage::saveBooks(books, BOOK_FILE);

    return success;
}
