// library_exceptions.h
#ifndef LIBRARY_EXCEPTIONS_H
#define LIBRARY_EXCEPTIONS_H

#include <stdexcept>
#include <string>

// 读者不存在异常
class ReaderNotFoundException : public std::runtime_error {
public:
    ReaderNotFoundException(const std::string& message) : std::runtime_error(message) {}
};

// 书籍不存在异常
class BookNotFoundException : public std::runtime_error {
public:
    BookNotFoundException(const std::string& message) : std::runtime_error(message) {}
};

// 借阅上限异常
class BorrowLimitExceededException : public std::runtime_error {
public:
    BorrowLimitExceededException(const std::string& message) : std::runtime_error(message) {}
};

// 未交罚款异常
class UnpaidFineException : public std::runtime_error {
public:
    UnpaidFineException(const std::string& message) : std::runtime_error(message) {}
};

// 书籍已归还异常
class BookAlreadyReturnedException : public std::runtime_error {
public:
    BookAlreadyReturnedException(const std::string& message) : std::runtime_error(message) {}
};

// 书籍未被借阅异常
class BookNotBorrowedException : public std::runtime_error {
public:
    BookNotBorrowedException(const std::string& message) : std::runtime_error(message) {}
};

// 超过续借次数异常
class RenewalLimitExceededException : public std::runtime_error {
public:
    RenewalLimitExceededException(const std::string& message) : std::runtime_error(message) {}
};

// 书籍已过期异常
class BookExpiredException : public std::runtime_error {
public:
    BookExpiredException(const std::string& message) : std::runtime_error(message) {}
};

#endif