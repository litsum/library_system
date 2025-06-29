#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <iostream>
#include <qstring>
#include <QStringListModel>

class reader { // 类名改为驼峰命名
public:
    // 默认构造函数（若需要）
    reader() = default;

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

    ~reader(){}; // 使用=default显式声明析构函数

    // 访问器（const成员函数）
    std::string getName() const { return name_; }
    std::string getPassword() const { return password_; }
    int getDebt() const { return debt_; }
    bool isLocked() const { return stat_; }


    // 修改器
    void setDebt(int amount) { debt_ = amount; }
    void setLocked() { stat_ = 1; }
    void setUnlocked() { stat_ = 0; }

    // 书籍借阅管理
    void borrowBook(const std::string& bookId) {
        borrowedBooks_.push_back(bookId);
    }

    //书架删除书籍
    bool returnBook(const std::string& bookId) {
        for (auto it = borrowedBooks_.begin(); it != borrowedBooks_.end(); ++it) {
            if (*it == bookId) {
                borrowedBooks_.erase(it);
                return true; // 删除成功
            }
        }
        return false; // 未找到该书
    }

    //保存用
    const std::vector<std::string>& getBorrowedBooks() const {
        return borrowedBooks_;
    }

    //书架
    QStringList borrowbooklist(){
        for(auto it=borrowedBooks_.begin();it<borrowedBooks_.end();++it){
            QString bo=QString::fromStdString(*it);
            booklist.append(bo);
        }
        return booklist;
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
    QStringList booklist;
};

#endif // READER_H
