#include <iostream>
#include <Windows.h>
#include "library.h"
#include "library_exceptions.h"
using namespace std;
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    SetConsoleOutputCP(65001);
    Library library;
    setTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "==========欢迎来到图书馆管理系统！==========" << endl;
    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    do{
        cout << endl;
        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN);
        cout << "请选择：1.系统管理；2.图书借阅；3.退出程序" << endl;
        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        int a;
        cin >> a;
        cout << endl;
        if(a == 1)
        {
            do
            {
                setTextColor(FOREGROUND_BLUE);
                cout << "请输入管理员密码:" << endl;
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                string pwd;
                cin >> pwd;
                if(pwd == "147258"){
                    setTextColor(FOREGROUND_GREEN);
                    cout << "=====欢迎登录=====" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }else{
                    setTextColor(FOREGROUND_RED);
                    cout << "密码错误！" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cout << "请选择：1.重新输入；2.退出" << endl;
                    cin >> a;
                    if(a == 1)
                    {
                        continue;
                    }else
                    {
                        break;
                    }
                }
            } while (1);
            do{
                cout << endl;
                setTextColor(FOREGROUND_GREEN);
                cout << "请选择一个功能:" << endl;
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "1. 添加一本书籍" << endl;
                cout << "2. 删除一本书籍" << endl;
                cout << "3. 获取指定图书信息" << endl;
                cout << "4. 获取全部图书信息" << endl;
                cout << "5. 获取全部读者信息" << endl;
                cout << "6. 返回主界面" << endl;
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                int choice; 
                cin >> choice;
                try{
                if(choice == 1)
                {
                    cout << endl;
                    int ifcontinue;
                    do{
                        setTextColor(FOREGROUND_BLUE);
                        cout << "请输入要添加的书籍信息:" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        string type, title, author, native, ISBN;
                        cout << "书籍类型: " << endl;
                        cin >> type;
                        cout << "书籍标题: " << endl;
                        cin >> title;
                        cout << "书籍作者: " << endl;
                        cin >> author;
                        cout << "作者国籍: " << endl;
                        cin >> native;
                        cout << "书籍ISBN: " << endl;
                        cin >> ISBN;
                        if(type == "Literature")
                        library.addBook(new Literature(title, author, native, ISBN));
                        else if(type == "Art")
                        library.addBook(new Art(title, author, native, ISBN));
                        else if(type == "SocialScience")
                        library.addBook(new SocialScience(title, author, native, ISBN));
                        else if(type == "Education")
                        library.addBook(new Education(title, author, native, ISBN));
                        else if(type == "Philosophy")
                        library.addBook(new Philosophy(title, author, native, ISBN));
                        else if(type == "NaturalScience")
                        library.addBook(new NaturalScience(title, author, native, ISBN));
                        else{
                            setTextColor(FOREGROUND_RED);
                            cout << "输入错误！" << endl;
                            setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====书籍添加成功！=====" << endl;
                        setTextColor(FOREGROUND_BLUE);
                        cout << "选择接下来操作:" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "1. 继续添加" << endl;
                        cout << "2. 退出添加" << endl;
                        cin >> ifcontinue;
                    }while (ifcontinue == 1);            
                }
                else if(choice == 2)
                {
                    cout << "请输入要删除的书籍的ISBN:" << endl;
                    string ISBN;
                    cin >> ISBN;
                    library.removeBook(ISBN);
                    setTextColor(FOREGROUND_GREEN);
                    cout << "=====书籍删除成功！=====" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else if(choice == 3)
                {
                    cout << "请输入要查找的图书的ISBN:" << endl;
                    string ISBN;
                    cin >> ISBN;
                    Book* book = library.findBook(ISBN);
                    if (book != nullptr) {
                        book->displayInfo();
                    } else {
                            setTextColor(FOREGROUND_RED);
                            cout << "=====未找到该图书=====" << endl;
                            setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                else if(choice == 4)
                {
                    const vector<Book*>& allBooks = library.getallBooks();
                    if (allBooks.empty()) {
                        setTextColor(FOREGROUND_RED);
                        cout << "=====没有找到任何图书！=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    } else {
                        for (const auto& book : allBooks) {
                        cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", ISBN: " << book->getISBN() << std::endl;
                        }
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====已显示所有图书信息=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                else if(choice == 5)
                {
                    const std::vector<Reader*>& allReaders = library.getallReaders();
                    if (allReaders.empty()) {
                        setTextColor(FOREGROUND_RED);
                        cout << "=====没有找到任何读者！=====" << std::endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }else {
                       for (const auto& reader : allReaders) {
                       std::cout << "Name: " << reader->getName() << ", ID: " << reader->getId() << std::endl;
                       }
                       setTextColor(FOREGROUND_GREEN);
                       cout << "=====已显示所有读者信息=====" << std::endl;
                       setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                }
                else if(choice == 6)
                {
                    break;
                }
                }catch(const std::exception& e) {
                    setTextColor(FOREGROUND_RED);
                    std::cerr << "发生异常: " << e.what() << std::endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }while(1);
        }
        else if(a == 2)
        {
            cout << endl;
            setTextColor(FOREGROUND_BLUE);
            cout << "是否为新读者用户?Yes/No" << endl;
            setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                string answer1;
                cin >> answer1;
                if(answer1 == "Yes")
                {
                    setTextColor(FOREGROUND_BLUE);
                    cout << "请输入读者信息:" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cout << "读者姓名: " << endl;
                    string name;
                    cin >> name;
                    int count = library.getTotalReaders();
                    int id = count + 1;
                    cout << "请设置读者密码: " << endl;
                    string pwd;
                    cin >> pwd;
                    library.addReader(new RegularMember(name, id, pwd));
                    cout << "读者的ID: " << id << endl;
                    setTextColor(FOREGROUND_GREEN);
                    cout << "=====读者添加成功！=====" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cout << endl;
                }
                cout << "请输入读者ID:(如果忘记ID,请输入0)" << endl;
                int id;
                cin >> id;
                if(id == 0)
                {
                    cout << "请输入读者姓名: " << endl;
                    string name;
                    cin >> name;
                    id = library.getReaderIdByName(name);
                }
                Reader* reader = library.findReader(id);
                do{
                    cout << "请输入密码: " << endl;
                    string pwd;
                    cin >> pwd;
                    if(reader->getPassword() == pwd)
                    {
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====登录成功！=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << endl;
                        break;
                    }else
                    {
                        setTextColor(FOREGROUND_RED);
                        cout << "密码错误！请选择1.重新输入；2.修改密码" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        int answer10;
                        cin >> answer10;
                        if(answer10 == 1)
                        {
                            continue;
                        }else if(answer10 == 2)
                        {
                            cout << "请输入管理员密码: " << std::endl;
                            string inputPwd;
                            cin >> inputPwd;
                            string adminPwd = "147258";
                            if (inputPwd == adminPwd) {
                            std::cout << "请输入新密码: " << std::endl;
                            std::string newPwd;
                            std::cin >> newPwd;
                            reader->setPassword(newPwd);
                            setTextColor(FOREGROUND_GREEN);
                            std::cout << "=====密码修改成功！=====" << std::endl;
                            setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            cout << endl;
                            }else{
                                setTextColor(FOREGROUND_RED);
                                std::cout << "管理员密码错误！" << std::endl;
                                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                return 0;
                            }
                        }
                    }
                }while(1);
            do{
                setTextColor(FOREGROUND_GREEN);
                cout << "请选择一个功能:" << endl;
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "1. 借一本书" << endl;
                cout << "2. 归还一本书" << endl;
                cout << "3. 续借书本" << endl;
                cout << "4. 积分兑换" << endl;
                cout << "5. 查看借阅记录" << endl;
                cout << "6. 返回主页面" << endl;
                setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                int choice; 
                cin >> choice;
                try{
                if(choice == 1)
                {
                    int ifcontinue;
                    do{
                        setTextColor(FOREGROUND_BLUE);
                        cout << "是否查看书籍推荐?Yes/No" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        string answer3;
                        cin >> answer3;
                        if(answer3 == "Yes")
                        {
                            library.generateRecommendations();
                        }
                        cout << "请输入要借的书籍名称:" << endl;
                        string ISBN;
                        string title;
                        cin >> title;
                        ISBN = library.getISBNByTitle(title);
                        library.borrowBook(id, ISBN);
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====借书成功！=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << endl;
                        setTextColor(FOREGROUND_BLUE);
                        cout << "选择接下来操作:" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "1. 继续借书" << endl;
                        cout << "2. 退出借书" << endl;
                        cin >> ifcontinue;
                    }while(ifcontinue == 1);
                }
                else if(choice == 2)
                {
                    int ifcontinue;
                    do{
                        cout << "请输入要还的书籍ISBN:(如果忘记ISBN,请输入forget)" << endl;
                        string ISBN;
                        cin >> ISBN;
                        if(ISBN == "forget")
                        {
                            cout << "请输入要还的书籍标题: " << endl;
                            string title;
                            cin >> title;
                            ISBN = library.getISBNByTitle(title);
                        }
                        library.returnBook(id, ISBN);
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====还书成功！=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << endl;
                        cout << "选择接下来操作:" << endl;
                        cout << "1. 继续还书" << endl;
                        cout << "2. 退出还书" << endl;
                        cin >> ifcontinue;
                    }while(ifcontinue == 1);
                }
                else if(choice == 3)
                {
                    int ifcontinue;
                    do{
                        cout << "请输入要续借的ISBN:(如果忘记ISBN,请输入forget)" << endl;
                        string ISBN;
                        cin >> ISBN;
                        if(ISBN == "forget")
                        {
                            cout << "请输入要续借的书籍标题: " << endl;
                            string title;
                            cin >> title;
                            ISBN = library.getISBNByTitle(title);
                        }
                        library.renewBook(id, ISBN);
                        setTextColor(FOREGROUND_GREEN);
                        cout << "=====续借成功！=====" << endl;
                        setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << endl;
                        cout << "选择接下来操作:" << endl;
                        cout << "1. 继续续借" << endl;
                        cout << "2. 退出续借" << endl;
                        cin >> ifcontinue;
                    }while(ifcontinue == 1);
                }
                else if(choice == 4)
                {
                    library.displayReaderPoints(id);
                    cout << "请输入要兑换的积分数量: " << endl;
                    int points;
                    cin >> points;
                    library.redeemPoints(id, points);
                }
                else if(choice == 5)
                {
                    const std::vector<BorrowRecord>& records = library.getReaderBorrowRecords(id);
                    for (const auto& record : records) {
                        cout << "ISBN: " << record.getISBN() << std::endl;
                        time_t borrowTime = record.getBorrowDate();
                        cout << "Borrow Date: " << ctime(&borrowTime) << std::endl;
                        time_t dueTime = record.getDueDate();
                        cout << "Due Date: " << ctime(&dueTime) << std::endl;
                        cout << "Is Returned: " << (record.getIsReturned() ? "Yes" : "No") << std::endl;
                        cout << std::endl;
                    }
                    setTextColor(FOREGROUND_GREEN);
                    cout << "=====借阅记录查询成功！=====" << endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else if(choice == 6)
                {
                    break;
                }
                }catch(const std::exception& e) {
                    setTextColor(FOREGROUND_RED);
                    std::cerr << "发生异常: " << e.what() << std::endl;
                    setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }while(1);
        }
        else if(a == 3)
        {
            setTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "==========感谢使用本系统！==========" << endl;
            setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }while(1);
    return 0;
}