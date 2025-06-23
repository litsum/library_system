#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include "borrow_record.h"

class Reader {
protected:
    std::string name;
    int id;
    int borrowPeriod;
    std::vector<BorrowRecord> borrowRecords;// 记录借阅记录
    double fine;
    int borrowCount;  // 记录借阅次数
    int maxBorrowCount;
    int points;
    std::string password;
public:
    Reader(const std::string& n, int i, std::string password, int points = 0,double fine = 0.0, int period = 0);
    virtual ~Reader();
    std::string getName() const;
    int getId() const;
    int getBorrowPeriod() const;// 获取借阅期限
    const std::vector<BorrowRecord>& getBorrowRecords() const;// 获取借阅记录
    double getFine() const;// 获取 Fine
    void addBorrowRecord(const BorrowRecord& record);// 增加借阅记录
    void updateFine(double amount);//  更新 Fine
    virtual void displayInfo() const;//  显示读者信息
    int getBorrowCount() const;  // 获取借阅次数
    void incrementBorrowCount(); // 增加借阅次数
    BorrowRecord* findBorrowRecord(const std::string& ISBN);// 查找借阅记录
    void calculateAndUpdateFine();// 计算并更新 Fine
    virtual int getMaxBorrowCount() const = 0;
    virtual int getMaxRenewalCount() const = 0; 
    int getPoints();
    void addPoints(int p);
    void deductPoints(int p);
    std::string getPassword() const; // 获取密码函数
    void setPassword(const std::string& newPwd); // 设置密码函数
};

class RegularMember : public Reader {
public:
    RegularMember(const std::string& n, int i,std::string password, int p=0, double f=0.0);
    void displayInfo() const override;
    int getMaxBorrowCount() const override;
    int getMaxRenewalCount() const override;
};

class VIPMember : public Reader {
public:
    VIPMember(const std::string& n, int i,std::string password, int p=0, double f=0.0);
    void displayInfo() const override;
    int getMaxBorrowCount() const override;
    int getMaxRenewalCount() const override;
};

#endif