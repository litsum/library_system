#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <iostream>
#include <qstring>
#include <QStringListModel>
#include "book.h"
#include <QDate>

class reader { // 类名改为驼峰命名
public:
    // 默认构造函数（若需要）
    reader() = default;
    bool isVip() const { return is_vip_; }

    // 构造函数
    reader(const std::string& name, const std::string& password)
        : name_(name), password_(password),valid(1), debt_(0), stat_(0) {} // 成员变量加下划线

    reader(const std::string& name, const std::string& password,std::vector<std::string> borrowedBooks_,int valid)
        : name_(name), password_(password),borrowedBooks_(borrowedBooks_),valid(valid), debt_(0), stat_(0) {}
    // 拷贝构造函数（保留深拷贝逻辑）
    reader(const reader& source)
        : name_(source.name_),
        password_(source.password_),
        borrowedBooks_(source.borrowedBooks_),
        valid(source.valid), // 重命名成员变量
        debt_(source.debt_),
        stat_(source.stat_)
            {}

    // 拷贝赋值运算符（建议显式声明，遵循 RAII 原则）
    reader& operator=(const reader& rhs) {
        if (this != &rhs) {
            name_ = rhs.name_;
            password_ = rhs.password_;
            borrowedBooks_ = rhs.borrowedBooks_;
            debt_ = rhs.debt_;
            stat_ = rhs.stat_;
            valid = rhs.valid;
        }
        return *this;
    }
    // 添加借书记录方法
    void borrowBook(const std::string& isbn, const QDate& borrowDate, const QDate& deadline) {
        borrowedBooks_.push_back(isbn);
        borrowDates_.push_back(borrowDate);
        deadlines_.push_back(deadline);
    }

    // 获取借阅记录
    const std::vector<std::string>& getBorrowedBooks() const { return borrowedBooks_; }
    const std::vector<QDate>& getBorrowDates() const { return borrowDates_; }
    const std::vector<QDate>& getDeadlines() const { return deadlines_; }

    ~reader(){}; // 使用=default显式声明析构函数

    // 访问器（const成员函数）
    std::string getName() const { return name_; }
    std::string getPassword() const { return password_; }
    int getDebt() const { return debt_; }
    bool isLocked() const { return stat_; }


    void setLocked() { stat_ = 1; }
    void setUnlocked() { stat_ = 0; }

    //书架
    QStringList borrowbooklist(){
        for(auto it=borrowedBooks_.begin();it!=borrowedBooks_.end();++it){
            QString bo=QString::fromStdString(*it);
            booklist.append(bo);
        }
        return booklist;
    }
    void addlist(std::string BO){
        QString bo=QString::fromStdString(BO);
        booklist.append(bo);
    }

    bool returnBook(const std::string& bookId) {
        for (auto it = borrowedBooks_.begin(); it != borrowedBooks_.end(); ++it) {
            if (*it == bookId) {
                borrowedBooks_.erase(it);
                return true; // 删除成功
            }
        }
        return false; // 未找到该书
    }
    void deletelist(QString tar){
        for(auto it=booklist.begin();it!=booklist.end();){
            if(*it==tar){it=booklist.erase(it);}
            else ++it;
        }
    }
    // 设置债务时自动更新VIP状态
    void setDebt(int amount) {
        debt_ = amount;
        is_vip_ = (amount == 0); // debt为0时是VIP，否则不是
    }
    void ban(){valid = 0;}//封禁读者

    void recover(){valid=1;}//解禁读者

    int getvalid() const{return valid;}

private:
    std::string name_;
    std::string password_;
    std::vector<std::string> borrowedBooks_;
    int valid ;// 重命名为更清晰的名称
    int debt_ ; // C++11后可直接初始化
    int stat_ ;
    bool is_vip_ = true; // 默认是VIP
    QStringList booklist;
    std::vector<QDate> borrowDates_;    // 借阅日期
    std::vector<QDate> deadlines_;      // 到期日期
};

#endif // READER_H
