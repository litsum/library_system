#include "library.h"
#include "library_exceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <unordered_map>
Library::Library()
    : booksFile("books.txt"), readersFile("readers.txt"), recordsFile("records.txt") {
    loadData();
    total_readers = readers.size();
    for (auto book : books) {
        isbnToBook[book->getISBN()] = book;
    }
    total_readers = readers.size();
    }

Library::~Library() {
    saveData();
    for (auto book : books) {
        delete book;
    }
    for (auto reader : readers) {
        delete reader;
    }
}

void Library::addBook(Book* book) {
    books.push_back(book);
    isbnToBook[book->getISBN()] = book;
}
void  Library::addReader(RegularMember* reader) {
    readers.push_back(reader);
    incrementReaderCount();
}
void Library::removeBook(const std::string& ISBN) {
    auto it = isbnToBook.find(ISBN);
    if (it != isbnToBook.end()) {
        auto bookIt = std::find_if(books.begin(), books.end(), [&ISBN](Book* book) {
            return book->getISBN() == ISBN;
        });
        if (bookIt != books.end()) {
            delete *bookIt;
            books.erase(bookIt);
            isbnToBook.erase(it); // 从哈希表中移除
        }
    }
}

Book* Library::findBook(const std::string& ISBN) {
    auto it = isbnToBook.find(ISBN);
    if (it != isbnToBook.end()) {
        return it->second;
    }
    return nullptr;
}

Reader* Library::findReader(int id) {
    for (auto reader : readers) {
        if (reader->getId() == id) {
            return reader;
        }
    }
    return nullptr;
}
bool Library::isReaderValid(int readerId) {
    Reader* reader = findReader(readerId);
    if (!reader) {
        std::cout << "读者 " << readerId << "不存在." << std::endl;
        return false;
    }
    return true;
}

bool Library::isBookValid(const std::string& ISBN) {
    Book* book = findBook(ISBN);
    if (!book) {
        std::cout << "书籍" << ISBN << "不存在." << std::endl;
        return false;
    }
    return true;
}

void Library::borrowBook(int readerId, const std::string& ISBN) {
    try {
        if (!isReaderValid(readerId)) {
            throw ReaderNotFoundException("读者不存在");
        }
        if (!isBookValid(ISBN)) {
            throw BookNotFoundException("书籍不存在");
        }

        Reader* reader = findReader(readerId);
        Book* book = findBook(ISBN);
        int currentBorrowCount = 0;
        for (const auto& record : reader->getBorrowRecords()) {
            if (!record.getIsReturned()) {
                currentBorrowCount++;
            }
        }

        if (currentBorrowCount >= reader->getMaxBorrowCount()) {
            throw BorrowLimitExceededException("读者 " + reader->getName() + " 借阅书籍已达上限.");
        }

        if (reader->getFine() > 0) {
            throw UnpaidFineException("读者 " + reader->getName() + " 有未交罚款，暂不可以借书。");
        }

        book->setTimesLending();
        book->setIsBorrowed();
        reader->addPoints(10);
        time_t now = time(nullptr);
        time_t dueDate = now + reader->getBorrowPeriod() * 24 * 60 * 60;
        BorrowRecord record(ISBN, now, dueDate);
        reader->addBorrowRecord(record);
    } catch (const std::exception& e) {
        std::cerr << "借阅失败: " << e.what() << std::endl;
    }
}

void Library::returnBook(int readerId, const std::string& ISBN) {
    try {
        if (!isReaderValid(readerId) || !isBookValid(ISBN)) {
            return;
        }

        Reader* reader = findReader(readerId);
        Book* book = findBook(ISBN);
        BorrowRecord* record = reader->findBorrowRecord(ISBN);

        if (!record) {
            throw BookNotBorrowedException("书籍 " + ISBN + " 现在没有被该读者借阅.");
        }

        if (record->getIsReturned()) {
            throw BookAlreadyReturnedException("书籍 " + ISBN + " 已归还。");
        }
        time_t now = time(nullptr);
        if (now <= record->getDueDate()) 
        {
            // 按时归还，增加积分
            reader->addPoints(5); // 每按时归还一本书获得 5 积分
            reader->incrementBorrowCount();
            upgradeMember(reader);// 升级会员
        }
        else if (now > record->getDueDate() && now <= record->getDueDate() + 7 * 24 * 60 * 60) 
        {
            // 超时归还，扣除积分，并收取fine
            reader->deductPoints(10); // 超时归还每扣除 10 积分
            reader->updateFine(0.5 * (now - record->getDueDate()) / (7 * 24 * 60 * 60)); // 超时归还每收取fine
            std::cout << "超时归还，扣除积分，并收取fine" << reader->getFine() << std::endl;
        }
        book->setIsReturned();
        record->setIsReturned(true);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
void Library::renewBook(int readerId, const std::string& ISBN) {
    try {
        if (!isReaderValid(readerId) || !isBookValid(ISBN)) {
            return;
        }

        Reader* reader = findReader(readerId);
        Book* book = findBook(ISBN);
        BorrowRecord* record = reader->findBorrowRecord(ISBN);

        if (!record || record->getIsReturned()) {
            throw BookNotBorrowedException("书籍 " + ISBN + " 现在没有被该读者借阅.");
        }

        time_t now = time(nullptr);
        if (now > record->getDueDate()) {
            throw BookExpiredException("书籍 " + ISBN + " 已经超过期限，不可续借.");
        }

        if (reader->getFine() > 0) {
            throw UnpaidFineException("读者 " + reader->getName() + " 未支付罚金，不可续借.");
        }

        if (record->getRenewalCount() >= reader->getMaxRenewalCount()) {
            throw RenewalLimitExceededException("读者 " + reader->getName() + " 已经达到这本书的最大续借次数。");
        }

        // 更新应还日期
        time_t newDueDate = now + reader->getBorrowPeriod() * 24 * 60 * 60;
        record->setDueDate(newDueDate);
        record->incrementRenewalCount();
        std::cout << "书籍 " + ISBN + " 被成功续借. 新归还日期: " << ctime(&newDueDate);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
void Library::displayBooks() const {
    for (auto book : books) {
        book->displayInfo();
    }
}

void Library::displayReaders() const {
    for (auto reader : readers) {
        reader->displayInfo();
    }
}

void Library::loadData() {
    std::ifstream bookFile(booksFile);
    if (bookFile.is_open()) {
        std::string line;
        while (std::getline(bookFile, line)) {
            std::istringstream iss(line);
            std::string type, title, author, native, ISBN;
            int quantity, timesLending;
            bool isBorrowed;
            if (iss >> type >> title >> author >> native >> ISBN >> quantity >> timesLending >> isBorrowed) {
                if (type == "Philosophy") {
                    books.push_back(new Philosophy(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                } else if (type == "SocialScience") {
                    books.push_back(new SocialScience(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                } else if (type == "Art") {
                    books.push_back(new Art(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                } else if (type == "Education") {
                    books.push_back(new Education(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                } else if (type == "Literature") {
                    books.push_back(new Literature(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                } else if (type == "NaturalScience") {
                   books.push_back(new NaturalScience(title, author, native, ISBN, quantity, timesLending, isBorrowed));
                }
            } else {
                std::cerr << "书籍文件格式错误" << std::endl;
            }
        }
        bookFile.close();
    }
    std::ifstream readerFile(readersFile);
    if (readerFile.is_open()) {
        std::string line;
        int lineNumber = 0;
        while (std::getline(readerFile, line)) {
            lineNumber++;
            std::istringstream iss(line);
            std::string type, name, password;
            int id;
            int points = 0; // 默认值
            double fine = 0.0; // 默认值
            if (iss >> type >> name >> id >> password >> points >> fine) {
                // 尝试读取积分和罚金，如果不存在则使用默认值
                if (points < 0) {
                    std::cerr << "警告: 第 " << lineNumber << " 行的积分值为负数，已重置为0。" << std::endl;
                    points = 0;
                }
                if (fine < 0) {
                    std::cerr << "警告: 第 " << lineNumber << " 行的罚款值为负数，已重置为0。" << std::endl;
                    fine = 0.0;
                }
                if (type == "RegularMember") {
                    readers.push_back(new RegularMember(name, id, password, points, fine));
                } else if (type == "VIPMember") {
                    readers.push_back(new VIPMember(name, id, password, points, fine));
                }
            }else {
                std::cerr << "错误: 在 readers.txt 文件的第 " << lineNumber << " 行数据格式错误: " << line << std::endl;
            }
        }
        readerFile.close();
    }
    std::ifstream recordFile(recordsFile);
    if (recordFile.is_open()) {
        int readerId;
        std::string ISBN;
        time_t borrowDate, dueDate;
        bool isReturned;
        while (recordFile >> readerId >> ISBN >> borrowDate >> dueDate >> isReturned) {
            Reader* reader = findReader(readerId);
            if (reader) {
                BorrowRecord record(ISBN, borrowDate, dueDate);
                record.setIsReturned(isReturned);
                reader->addBorrowRecord(record);
            }
        }
        recordFile.close();
    }
}

void Library::saveData() {
    std::sort(books.begin(), books.end(), [](const Book* a, const Book* b) {
        return a->getISBN() < b->getISBN();
    });
    std::ofstream bookFile(booksFile);
    if (bookFile.is_open()) {
        for (auto book : books) {
            Philosophy* philosophy = dynamic_cast<Philosophy*>(book);
            if (philosophy) {
                bookFile << "Philosophy " << philosophy->getTitle() << " " << philosophy->getAuthor() << " " << philosophy->getNative() << " "
                         << philosophy->getISBN() << " " << philosophy->getQuantity() << " " << philosophy->getTimesLending() << " " 
                         << philosophy->getIsBorrowed() << " " << std::endl;
            } else {
                SocialScience* social = dynamic_cast<SocialScience*>(book);
                if (social) {
                    bookFile << "SocialScience " << social->getTitle() << " " << social->getAuthor() << " " << social->getNative() << " "
                             << social->getISBN() << " " << social->getQuantity() << " " << social->getTimesLending() << " " 
                             << social->getIsBorrowed() << " " << std::endl;
                } else {
                    NaturalScience* natural = dynamic_cast<NaturalScience*>(book);
                    if (natural) {
                        bookFile << "NaturalScience " << natural->getTitle() << " " << natural->getAuthor() << " " << natural->getNative() << " "
                                 << natural->getISBN() << " " << natural->getQuantity() << " " << natural->getTimesLending() << " " 
                                 << natural->getIsBorrowed() << " " << std::endl;
                    } else {
                        Education* education = dynamic_cast<Education*>(book);
                        if (education) {
                            bookFile << "Education " << education->getTitle() << " " << education->getAuthor() << " " << education->getNative() << " "
                                     << education->getISBN() << " " << education->getQuantity() << " " << education->getTimesLending() << " " 
                                     << education->getIsBorrowed() << " " << std::endl;
                        } else {
                            Literature* literature = dynamic_cast<Literature*>(book);
                            if (literature) {
                                bookFile << "Literature " << literature->getTitle() << " " << literature->getAuthor() << " " << literature->getNative() << " "
                                         << literature->getISBN() << " " << literature->getQuantity() << " " << literature->getTimesLending() << " " 
                                         << literature->getIsBorrowed() << " " << std::endl;
                            }else {
                                Art* art = dynamic_cast<Art*>(book);
                                if (art) {
                                    bookFile << "Art " << art->getTitle() << " " << art->getAuthor() << " " << art->getNative() << " "
                                             << art->getISBN() << " " << art->getQuantity() << " " << art->getTimesLending() << " " 
                                             << art->getIsBorrowed() << " " << std::endl;
                               }
                            }
                        }
                    }
                }
            }
            }
        }
        bookFile.close();
        std::ofstream readerFile(readersFile);
        if (readerFile.is_open()) {
            for (auto reader : readers) {
                RegularMember* regular = dynamic_cast<RegularMember*>(reader);
                if (regular) {
                    readerFile << "RegularMember " << regular->getName() << " " << regular->getId() << " " << regular->getPassword() << " "
                               << regular->getPoints() << " " << regular->getFine() << std::endl;
                } else {
                    VIPMember* vip = dynamic_cast<VIPMember*>(reader);
                    if (vip) {
                        readerFile << "VIPMember " << vip->getName() << " " << vip->getId() << " " << regular->getPassword() << " "
                                   << vip->getPoints() << " " << vip->getFine() << std::endl;
                    }
                }
            }
            readerFile.close();
        }

    std::ofstream recordFile(recordsFile);
    if (recordFile.is_open()) {
        for (auto reader : readers) {
            for (const auto& record : reader->getBorrowRecords()) {
                recordFile << reader->getId() << " " << record.getISBN() << " "
                           << record.getBorrowDate() << " " << record.getDueDate() << " "
                           << record.getIsReturned() << std::endl;
            }
        }
        recordFile.close();
    }
}

void Library::upgradeMember(Reader* reader) {
    RegularMember* regular = dynamic_cast<RegularMember*>(reader);
    if (regular && regular->getBorrowCount() >= 10) {
        std::string name = regular->getName();
        int id = regular->getId();
        std::string password = regular->getPassword();
        // 移除原有的普通会员
        for (auto it = readers.begin(); it != readers.end(); ++it) {
            if (*it == regular) {
                delete *it;
                readers.erase(it);
                break;
            }
        }
        // 添加新的 VIP 会员
        readers.push_back(new VIPMember(name, id, password));
        std::cout << "读者" << name << "升级成为会员。" << std::endl;
    }
}
void Library::generateRecommendations() const {
    std::unordered_map<std::string, std::vector<Book*>> typeBooks;

    // 按书的类型分组
    for (auto book : books) {
        typeBooks[book->getType()].push_back(book);
    }

    // 为每种类型的书按借阅次数排序并输出推荐书目
    for (const auto& pair : typeBooks) {
        std::string type = pair.first;
        std::vector<Book*> booksOfType = pair.second;

        // 按借阅次数排序
        std::sort(booksOfType.begin(), booksOfType.end(), [](Book* a, Book* b) {
            return a->getTimesLending() > b->getTimesLending();
        });

        std::cout << type << "类的推荐书籍为：" << std::endl;
        for (int i = 0; i < std::min(3, static_cast<int>(booksOfType.size())); ++i) {
            std::cout << i + 1 << ". " << booksOfType[i]->getTitle() << " (被借阅"
                      << booksOfType[i]->getTimesLending() << "次)" << std::endl;
        }
        std::cout << std::endl;
    }
}
// 通过书名获取 ISBN
std::string Library::getISBNByTitle(const std::string& title) {
    for (auto book : books) {
        if (book->getTitle() == title) {
            return book->getISBN();
        }
    }
    return ""; // 如果未找到，返回空字符串
}
// 通过读者名字获取读者 ID
int Library::getReaderIdByName(const std::string& name) {
    for (auto reader : readers) {
        if (reader->getName() == name) {
            return reader->getId();
        }
    }
    return -1; // 如果未找到，返回 -1
}
const std::vector<Book*>& Library::getallBooks() const {
    return books;
}
const std::vector<Reader*>& Library::getallReaders() const{
    return readers;
}
const std::vector<BorrowRecord>& Library::getReaderBorrowRecords(int readerId) {
    static std::vector<BorrowRecord> emptyRecords;
    Reader* reader = findReader(readerId);
    if (reader) {
        return reader->getBorrowRecords();
    }
    return emptyRecords;
}
void Library::redeemPoints(int readerId, int points) {
    Reader* reader = findReader(readerId);
    if (reader) {
        if (reader->getPoints() >= points) {
            // 扣除积分
            reader->deductPoints(points);
            std::cout << "积分兑换成功，扣除 " << points << " 积分！" << std::endl;
        } else {
            std::cout << "积分不足，无法兑换！" << std::endl;
        }
    }
}
// 显示读者积分
void Library::displayReaderPoints(int readerId) {
    Reader* reader = findReader(readerId);
    if (reader) {
        std::cout << "读者 " << reader->getName() << " 的积分为：" << reader->getPoints() << std::endl;
    }
}

// 实现 incrementReaderCount 函数
void Library::incrementReaderCount() {
    total_readers++;
}

// 实现 getTotalReaders 函数
int Library::getTotalReaders() const {
    return total_readers;
}