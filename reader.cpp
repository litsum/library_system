#include "reader.h"
#include <iostream>

Reader::Reader(const std::string& n, int i, std::string password, int points,double fine, int period)
    : name(n), id(i), password(password) ,points(points),fine(fine),borrowPeriod(period), borrowCount(0) {}

Reader::~Reader() {}

std::string Reader::getName() const {
    return name;
}

int Reader::getId() const {
    return id;
}

int Reader::getBorrowPeriod() const {
    return borrowPeriod;
}

const std::vector<BorrowRecord>& Reader::getBorrowRecords() const {
    return borrowRecords;
}

double Reader::getFine() const {
    return fine;
}

void Reader::addBorrowRecord(const BorrowRecord& record) {
    borrowRecords.push_back(record);
    incrementBorrowCount(); // 每次借阅增加借阅次数
}

void Reader::updateFine(double amount) {
    fine += amount;
}

void Reader::displayInfo() const {
    std::cout << "Name: " << name << ", ID: " << id << ", Fine: " << fine << std::endl;
}

int Reader::getBorrowCount() const {
    return borrowCount;
}

void Reader::incrementBorrowCount() {
    borrowCount++;
}
BorrowRecord* Reader::findBorrowRecord(const std::string& ISBN) {
    for (auto& record : borrowRecords) {
        if (record.getISBN() == ISBN) {
            return &record;
        }
    }
    return nullptr;
}
void Reader::calculateAndUpdateFine() {
    double finePerDay = 2.0;
    time_t now = time(nullptr);
    for (auto& record : borrowRecords) {
        if (!record.getIsReturned() && now > record.getDueDate()) {
            double overdueDays = difftime(now, record.getDueDate()) / (24 * 60 * 60);
            double overdueFine = overdueDays * finePerDay;
            updateFine(overdueFine);
            record.setIsReturned(true);
        }
    }
}
std::string Reader::getPassword() const {
    return password;
}
void Reader::setPassword(const std::string& newPwd) {
    password = newPwd;
}
RegularMember::RegularMember(const std::string& n, int i, std::string password, int p, double f)
    : Reader(n, i, password, p, 0.0, 30) {}// 30天借阅
int RegularMember::getMaxBorrowCount() const {
        return 3;  // 普通会员最大借阅数量为 3 本
    }
int RegularMember::getMaxRenewalCount() const {
    return 1;  // 普通会员最多续借 1 次
}
        
void RegularMember::displayInfo() const {
    std::cout << "Regular Member - ";
    Reader::displayInfo();
}

VIPMember::VIPMember(const std::string& n, int i, std::string password, int p, double f)
    : Reader(n, i, password , p, 0.0, 60) {}// 60天借阅
int VIPMember::getMaxBorrowCount() const {
    return 5;  // VIP 会员最大借阅数量为 5 本
}
int VIPMember::getMaxRenewalCount() const {
    return 2;  // VIP 会员最多续借 2 次
}
void VIPMember::displayInfo() const {
    std::cout << "VIP Member - ";
    Reader::displayInfo();
}
int Reader::getPoints(){
    return points;
}

void Reader::addPoints(int p) {
    points += p;
}

void Reader::deductPoints(int p) {
    if (points >= p) {
        points -= p;
    } else {
        // 处理积分不足的情况
        std::cout << "积分不足，无法扣除！" << std::endl;
    }
}