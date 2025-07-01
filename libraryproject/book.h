#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
public:
    // 构造函数
    Book(const std::string& name, const std::string& author,
         const std::string& publisher, const std::string& isbn,
         const std::string& type)
        : name(name), author(author), publisher(publisher),ISBN(isbn),type(type) {
         }
    // 获取书名
    std::string getName() const { return name; }
    // 获取作者
    std::string getAuthor() const { return author; }
    // 获取出版社
    std::string getPublisher() const { return publisher; }
    // 获取isbn
    std::string getisbn() const { return ISBN;}
    std::string getType() const { return type; }
    void setType(const std::string& t) { type = t; }
    bool isAvailable() const { return available; }
    void setAvailable(bool avail) { available = avail; }
private:
    std::string name;      // 书名
    std::string author;    // 作者
    std::string publisher; // 出版社
    std::string ISBN;
    std::string type;
    bool available = true;    // ISBN号
};

#endif // BOOK_H
