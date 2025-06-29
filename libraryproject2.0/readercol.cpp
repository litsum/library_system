#include "readercol.h"
#include "ui_readercol.h"
#include "book.h"
#include "database.h"
#include "search.h"
#include <QMessageBox>
#include <QMenu>
#include <QStandardItem>
#include <QHeaderView>

readercol::readercol(QWidget *parent)
    : QDialog(parent), ui(new Ui::readercol)
{
    ui->setupUi(this);

    // 初始化模型
    model = new QStringListModel(this);
    _model = new QStandardItemModel(0, 5, this); // 确保正确初始化

    // 设置表头
    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社", "状态"});

    // 获取当前登录的读者
    currentReader = nullptr;
    for(auto &reader : db.readers) {
        if(reader.isLocked()) { // 假设 isLocked 表示已登录
            currentReader = &reader;
            break;
        }
    }

    if(!currentReader) {
        QMessageBox::warning(this, "错误", "未找到登录的读者!");
        return;
    }

    // 显示当前读者的借阅列表
    model->setStringList(currentReader->borrowbooklist());
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑

    // 加载所有图书到表格
    loadAllBooks();

    // 设置表格属性
    ui->tableView->setModel(_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 右键菜单 - 借书功能
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, &QTableView::customContextMenuRequested,
            this, &readercol::showContextMenu);

    // 初始化还书功能右键菜单
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, &QListView::customContextMenuRequested,
            this, &readercol::showReturnMenu);
}

readercol::~readercol()
{
    delete ui;
}

void readercol::loadAllBooks()
{
    _model->removeRows(0, _model->rowCount());

    int row = 0;
    for(const auto &book : db.books) {
        QList<QStandardItem*> rowItems;

        // ISBN
        QString isbn = QString::fromStdString(book.getISBN());
        QStandardItem *isbnItem = new QStandardItem(isbn);
        isbnItem->setEditable(false);

        // 书名
        QString name = QString::fromStdString(book.getName());
        QStandardItem *nameItem = new QStandardItem(name);

        // 作者
        QString author = QString::fromStdString(book.getAuthor());
        QStandardItem *authorItem = new QStandardItem(author);

        // 出版社
        QString publisher = QString::fromStdString(book.getPublisher());
        QStandardItem *publisherItem = new QStandardItem(publisher);

        // 状态
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(book.isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(book.isAvailable() ? "可借阅" : "已借出");
        statusItem->setEditable(false);

        rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;
        _model->appendRow(rowItems);
        row++;
    }
}

void readercol::showContextMenu(const QPoint &pos)
{
    if(!currentReader) return;

    QModelIndex index = ui->tableView->indexAt(pos);
    if(!index.isValid()) return;

    QString bookName = _model->index(index.row(), 1).data().toString();
    std::string bookNameStr = bookName.toStdString();

    // 检查是否已借阅
    bool alreadyBorrowed = false;
    for(const auto &borrowed : currentReader->getBorrowedBooks()) {
        if(borrowed == bookNameStr) {
            alreadyBorrowed = true;
            break;
        }
    }

    QMenu menu;
    QAction *borrowAction = menu.addAction("借阅图书");
    borrowAction->setEnabled(!alreadyBorrowed);

    if(menu.exec(ui->tableView->viewport()->mapToGlobal(pos))) {
        // 查找图书
        auto bookIt = std::find_if(db.books.begin(), db.books.end(),
            [&](const Book& b) { return b.getName() == bookNameStr; });

        if(bookIt != db.books.end()) {
            if(bookIt->isAvailable()) {
                currentReader->borrowBook(bookNameStr);
                bookIt->setAvailable(false);
                QMessageBox::information(this, "成功", "借阅成功!");
                refreshBookList();
                loadAllBooks(); // 刷新图书状态
            } else {
                QMessageBox::warning(this, "失败", "图书已被借出!");
            }
        }
    }
}

void readercol::showReturnMenu(const QPoint &pos)
{
    if(!currentReader) return;

    QModelIndex index = ui->listView->indexAt(pos);
    if(!index.isValid()) return;

    QString bookName = model->data(index).toString();
    std::string bookNameStr = bookName.toStdString();

    QMenu menu;
    QAction *returnAction = menu.addAction("归还图书");

    if(menu.exec(ui->listView->viewport()->mapToGlobal(pos))) {
        for(auto bookIt=db.books.begin();bookIt!=db.books.end();++bookIt)
        if(bookIt->getName()==bookNameStr) {
            currentReader->returnBook(bookNameStr);
            bookIt->setAvailable(true);
            QMessageBox::information(this, "成功", "归还成功!");
            currentReader->deletelist(bookName);
            refreshBookList();
            loadAllBooks(); // 刷新图书状态
            break;
        }
    }
}

void readercol::on_borrowbook_clicked()
{
    FindDialog fi;
    fi.exec();
    // 假设查找对话框会刷新数据
    refreshBookList();
    loadAllBooks();
}

void readercol::on_pay_clicked()
{
    if(currentReader) {
        double debt = currentReader->getDebt();
        QMessageBox::information(this, "欠款信息",
            QString("您当前的欠款为：%1 元").arg(debt));
    }
}

void readercol::on_pushButton_2_clicked()
{
    QString content = ui->lineEdit_2->text().trimmed();
    if(!content.isEmpty()) {
        // 搜索功能实现
        // 可以调用 FindDialog 中的搜索方法
    }
}

void readercol::refreshBookList()
{
    if(currentReader) {
        model->setStringList(currentReader->borrowbooklist());
    }
}
