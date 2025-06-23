#include "borrow_record.h"
BorrowRecord::BorrowRecord(const std::string& isbn, time_t borrow, time_t due)
    : ISBN(isbn), borrowDate(borrow), dueDate(due), isReturned(false) {}
std::string BorrowRecord::getISBN() const {
    return ISBN;
}
time_t BorrowRecord::getBorrowDate() const {
    return borrowDate;
}
time_t BorrowRecord::getDueDate() const {
    return dueDate;
}
bool BorrowRecord::getIsReturned() const {
    return isReturned;
}
void BorrowRecord::setIsReturned(bool returned) {
    isReturned = returned;
}
std::string BorrowRecord::formatDate(time_t date) const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&date));
    return buffer;
}
void BorrowRecord::displayInfo() const {
    std::cout << "编码: " << ISBN << std::endl;
    std::cout << "借阅时间: " << formatDate(borrowDate) << std::endl;
    std::cout << "应归还时间: " << formatDate(dueDate) << std::endl;
    std::cout << "是否归还: " << (isReturned ? "是" : "否") << std::endl;
}
int BorrowRecord::getRenewalCount() const {
    return renewalCount;
}

void BorrowRecord::incrementRenewalCount() {
    renewalCount++;
}

void BorrowRecord::setDueDate(time_t newDueDate) {
    dueDate = newDueDate;
}
