#include "book.h"
int Book::total_books = 0;
Book::Book(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    : title(title), author(author), native(native), ISBN(ISBN),quantity(quantity),times_lending(times_lending),isBorrowed(isBorrowed)
{
    total_books++;
};
std::string Book::getTitle() const
{
    return title;
}
std::string Book::getAuthor() const
{
    return author;
}
std::string Book::getNative() const
{
    return native;
}
std::string Book::getISBN() const
{
    return ISBN;
}
bool Book::getIsBorrowed() const
{
    return isBorrowed;
}
void Book::setIsBorrowed()
{
    quantity--;
    if(quantity==0)
        isBorrowed=true;
}
void Book::setIsReturned()
{
    quantity++;
    if(quantity>0)
        isBorrowed=false;
}
int Book::getQuantity() 
{
    return quantity;
}
int Book::getTimesLending()
{
    return times_lending;
}
void Book::setTimesLending()
{
    times_lending++;
}
int Book::getTotalBooks()
{
    return total_books;
}
void Book::displayInfo() const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\n";
}
std::string Book::getType() const
{
    return "Book";
}
Philosophy::Philosophy(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Philosophy Book"){}
std::string Philosophy::getType() const
{
    return type;
}
void Philosophy::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}
SocialScience::SocialScience(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Social Science Book"){}
std::string SocialScience::getType() const
{
    return type;
}
void SocialScience::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}
Education::Education(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Education Book"){}
std::string Education::getType() const
{
    return type;
}
void Education::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}
Literature::Literature(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Literature Book"){}
std::string Literature::getType() const
{
    return type;
}
void Literature::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}
Art::Art(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Art Book"){}
std::string Art::getType() const
{
    return type;
}
void Art::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}
NaturalScience::NaturalScience(const std::string& title, const std::string& author, const std::string& native, const std::string& ISBN,int quantity,int times_lending,bool isBorrowed)
    :Book(title, author, native, ISBN, quantity, times_lending, isBorrowed),type("Nature Science Book"){}
std::string NaturalScience::getType() const
{
    return type;
}
void NaturalScience::display()const
{
    std::cout << "书名: " << getTitle() << "\n作者: " << getAuthor() << "[" << getNative() << "]\nISBN: " << getISBN() << "\nType: " << type << "\n";
}