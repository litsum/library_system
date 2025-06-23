#ifndef BORROW_RECORD_H
#define BORROW_RECORD_H

#include <iostream>
#include <string>
#include <ctime>

class BorrowRecord {
private:
    std::string ISBN;
    time_t borrowDate;
    time_t dueDate;
    bool isReturned;
    int renewalCount;
public:
    BorrowRecord(const std::string& isbn, time_t borrow, time_t due);
    std::string getISBN() const;//  获取ISBN
    time_t getBorrowDate() const;//  获取借阅日期
    time_t getDueDate() const;// 获取借阅日期
    bool getIsReturned() const;//  获取是否已还
    void setIsReturned(bool returned);// 设置是否已还
    void displayInfo() const;// 显示借阅记录信息
    int getRenewalCount() const;  // 获取续借次数
    void incrementRenewalCount();  // 增加续借次数
    void setDueDate(time_t newDueDate);  // 设置新的应还日期
    std::string formatDate(time_t date) const;
};

#endif    