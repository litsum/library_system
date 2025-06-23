#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book 
{
protected:
    std::string title;
    std::string author;
    std::string native;// 作者籍贯
    std::string ISBN;// ISBN号
    int quantity;// 每本书数量
    int times_lending;// 借阅次数
    bool isBorrowed;// 是否被全部借阅
    static int total_books;// 书籍总数
public:
    Book(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getNative() const;
    std::string getISBN() const;
    bool getIsBorrowed() const;
    void setIsBorrowed();
    void setIsReturned();
    int getQuantity();
    int getTimesLending();
    void setTimesLending();
    static int getTotalBooks();
    virtual void displayInfo() const;
    virtual std::string getType() const;
};
class Philosophy:public Book
{
private:
    std::string type;
public:
    Philosophy(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
class SocialScience:public Book
{
private:
    std::string type;
public:
    SocialScience(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
class Education:public Book
{
private:
    std::string type;
public:
    Education(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
class Literature:public Book
{
private:
    std::string type;
public:
    Literature(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
class Art:public Book
{
private:
    std::string type;
public:
    Art(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
class NaturalScience:public Book
{
private:
    std::string type;
public:
    NaturalScience(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity=5,int times_lending=0,bool isBorrowed=false);
    std::string getType() const;
    void display() const;// 显示
};
#endif