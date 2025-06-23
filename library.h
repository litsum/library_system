#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <unordered_map>
#include "book.h"
#include "reader.h"
#include "borrow_record.h"

class Library {
private:
    std::vector<Book*> books;// 图书列表
    std::vector<Reader*> readers;// 读者列表
    std::string booksFile;// 文件名
    std::string binaryBooksFile;// 文件名
    std::string readersFile;// 文件名
    std::string binaryReadersFile;
    std::string recordsFile;// 文件名
    std::string binaryRecordsFile;
    void upgradeMember(Reader* reader); // 会员升级方法
    bool isReaderValid(int readerId);
    bool isBookValid(const std::string& ISBN);
    int total_readers;
    std::unordered_map<std::string, Book*> isbnToBook;
public:
    Library();
    ~Library();
    void addBook(Book* book);// 添加图书
    void addReader(RegularMember* reader);// 添加读者
    void removeBook(const std::string& ISBN);// 删除图书
    Book* findBook(const std::string& ISBN);// 查找图书
    Reader* findReader(int id);//  查找读者
    void borrowBook(int readerId, const std::string& ISBN);// 借书
    void returnBook(int readerId, const std::string& ISBN);// 还书
    void renewBook(int readerId, const std::string& ISBN);// 续借
    void displayBooks() const;// 显示图书列表
    void displayReaders() const;// 显示读者列表
    void loadData();//  加载数据
    void saveData();// 保存数据
    void generateRecommendations() const;// 生成推荐
    std::string getISBNByTitle(const std::string& title); // 通过书名获取 ISBN
    int getReaderIdByName(const std::string& name); // 通过读者名字获取读者 ID
    const std::vector<Book*>& getallBooks() const;//  获取图书列表
    const std::vector<Reader*>& getallReaders() const;// 获取读者列表
    const std::vector<BorrowRecord>& getReaderBorrowRecords(int readerId); // 获取读者借阅记录
    void redeemPoints(int readerId, int points); // 兑换积分
    void displayReaderPoints(int readerId); // 显示读者积分
    void incrementReaderCount(); // 增加读者计数
    int getTotalReaders() const; // 获取读者总数
};

#endif