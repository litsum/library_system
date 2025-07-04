#include "readercol.h"
#include "ui_readercol.h"
#include "book.h"
#include "librarydatabase.h"
#include "ai_progress.h"
#include "audio_recorder.h"
#include "database.h"
#include <QMessageBox>
#include <QMenu>
#include <QStandardItem>
#include <QHeaderView>
#include "find.h"
#include <QDate>
#include <QSqlQuery>
#include <QRegularExpression>


readercol::readercol(QWidget *parent)
    : QDialog(parent), ui(new Ui::readercol)
{
    ui->setupUi(this);
    isRecording = false;
    ui->record_bgn->setText("开始录音");
    // 初始化模型
    model = new QStringListModel(this);
    _model = new QStandardItemModel(0, 5, this); // 确保正确初始化

    // 设置表头
    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社", "状态"});
    //LibraryDatabase& dbInstance = LibraryDatabase::getInstance();

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
    refreshBookList();

    // 加载所有图书到表格
    loadAllBooks();
    ui->comboBox->addItem("ISBN", 0);
    ui->comboBox->addItem("书名", 1);
    ui->comboBox->addItem("作者", 2);
    ui->comboBox->addItem("出版社", 3);
    ui->comboBox->addItem("种类", 4);

    // 设置表格属性
    BookSearchProxyModel *proxyModel = new BookSearchProxyModel(this);
    proxyModel->setSourceModel(_model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->lineEdit, &QLineEdit::textChanged,
            [proxyModel](const QString &text) {
                proxyModel->setSearchPrefix(text);
            });
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [proxyModel](int index) {
                proxyModel->setSearchColumn(index);
            });
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,
            &readercol::textchange);

    // 右键菜单 - 借书功能
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, &QTableView::customContextMenuRequested, [this, proxyModel](const QPoint &pos){
        QModelIndex index = ui->tableView->indexAt(pos);
        QMenu menu;
        QAction *borrowAction = menu.addAction("借阅图书");
        if (borrowAction == menu.exec(ui->tableView->viewport()->mapToGlobal(pos))) {

            if (index.isValid()) {
                // 映射到源模型索引
                QModelIndex sourceIndex = proxyModel->mapToSource(index);
                if (sourceIndex.isValid()) {
                    QString name = _model->item(sourceIndex.row(), 1)->text();
                    std::string Name = name.toUtf8().toStdString();
                    bool alreadyBorrowed = false;
                    for(const auto &borrowed : currentReader->getBorrowedBooks()) {
                        if(borrowed == Name) {
                            alreadyBorrowed = true;
                            break;
                        }
                    }
                    borrowAction->setEnabled(!alreadyBorrowed);
                    // 获取LibraryDatabase实例
                    //LibraryDatabase& dbInstance = LibraryDatabase::getInstance();
                    //auto& books = dbInstance.getBook();
                    auto bookIt = std::find_if(db.books.begin(), db.books.end(),
                                               [&](const Book& b) { return b.getName() == Name; });

                    if(bookIt != db.books.end()) {
                        if(bookIt->isAvailable()) {
                            QDate borrowDate = QDate::currentDate();
                            QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
                            currentReader->borrowBook(Name, borrowDate, deadlineDate);
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
        }
    });
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
    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社", "种类","状态"});

    //int row = 0;
    for(const auto &book : db.books) {
        QList<QStandardItem*> rowItems;

        // ISBN
        QString isbn = QString::fromStdString(book.getisbn());
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

        //种类
        QString type = QString::fromStdString(book.getType());
        QStandardItem *typeItem = new QStandardItem(type);

        // 状态
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(book.isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(book.isAvailable() ? "可借阅" : "已借出");
        statusItem->setEditable(false);

        rowItems << isbnItem << nameItem << authorItem << publisherItem << typeItem <<statusItem ;
        _model->appendRow(rowItems);
        //row++;
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
                QDate borrowDate = QDate::currentDate();
                QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
                currentReader->borrowBook(bookNameStr, borrowDate, deadlineDate);
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
    QStringList name = bookName.split(" ");
    std::string bookNameStr = name[0].toStdString();

    QMenu menu;
    menu.addAction("归还图书");

    if(menu.exec(ui->listView->viewport()->mapToGlobal(pos))) {
        // 获取LibraryDatabase实例
        LibraryDatabase& dbInstance = LibraryDatabase::getInstance();
        //auto& books = dbInstance.getBook();
        for(auto bookIt=db.books.begin();bookIt!=db.books.end();++bookIt){
            if(bookIt->getName()==bookNameStr) {
                currentReader->returnBook(bookNameStr);
                bookIt->setAvailable(true);
                currentReader->deletelist(bookName);
                if (dbInstance.saveData()) {
                    refreshBookList();
                    QMessageBox::information(this, "成功", "归还成功!");
                    loadAllBooks(); // 刷新图书状态
                } else {
                    QMessageBox::warning(this, "错误", "保存数据失败!");
                }
                break;
            }
        }
    }
}

QString readercol::cut_llm_response(QString ai_output){
    currentReader = nullptr;
    for(auto &reader : db.readers) {
        if(reader.isLocked()) { // 假设 isLocked 表示已登录
            currentReader = &reader;
            break;
        }
    }
    QRegularExpression rx("\\[([^\\]]+)\\]");
    QRegularExpressionMatchIterator i = rx.globalMatch(ai_output);
    QStringList parts;

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        parts << match.captured(1);
    }
    qDebug() << "字符串解析成功";
    // 提取部分，处理可能不存在的情况
    QString part1 = (parts.size() >= 1) ? parts[0] : QString();
    QString part2 = (parts.size() >= 2) ? parts[1] : QString();

    QString part3 = (parts.size() >= 3) ? parts[2] : QString();
    std::string value = part3.toUtf8().toStdString();
    std::int8_t function = part2.toUtf8().toInt();
    qDebug() << "调用的功能"<<function;
    qDebug() << "传递的参数"<<value;

    switch (function) {
    case 0:
        break;
    case 1://借书
    {
        qDebug() << "正调用借书函数";
        auto bookIt = std::find_if(db.books.begin(), db.books.end(),
                                   [&](const Book& b) { return b.getName() == value; });
        if(bookIt != db.books.end()) {
            if(bookIt->isAvailable()) {
                QDate borrowDate = QDate::currentDate();
                QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
                currentReader->borrowBook(value, borrowDate, deadlineDate);
                bookIt->setAvailable(false);
            }
        }
        refreshBookList();
        loadAllBooks(); // 刷新图书状态
        qDebug() << "ai借书成功";
    }
    default:
        break;
    }
    return part1;
}


void readercol::refreshBookList()
{
    if (!currentReader) return;

    model->removeRows(0, model->rowCount());
    QStringList bookList;

    //const auto& borrowedBooks = currentReader->getBorrowedBooks();
    //const auto& borrowDates = currentReader->getBorrowDates();
    //const auto& deadlines = currentReader->getDeadlines();

    for (size_t i = 0; i < currentReader->getBorrowedBooks().size(); i++) {
        QString bookInfo = QString("%1 (借于: %2, 到期: %3)")
                               .arg(QString::fromStdString(currentReader->getBorrowedBooks()[i]))
                               .arg(currentReader->getBorrowDates()[i].toString("yyyy-MM-dd"))
                               .arg(currentReader->getDeadlines()[i].toString("yyyy-MM-dd"));

        // 高亮显示逾期书籍
        if (QDate::currentDate() > currentReader->getDeadlines()[i]) {
            bookInfo = "<font color='red'>" + bookInfo + "</font>";
            currentReader->setDebt(10+currentReader->getDebt());
        }
        bookList.append(bookInfo);
    }
    model->setStringList(bookList);
    if(currentReader->getDebt()<0){
        ui->label->setText("当前账户状态：欠款");
        ui->label_3->setText(QString("当前欠款：%1").arg(currentReader->getDebt()));
        ui->label_2->setText("当前用户等级：普通用户");
    }else {
        ui->label->setText("当前账户状态：正常");
        ui->label_3->setText("当前欠款：0元");
        ui->label_2->setText("当前用户等级：VIP用户");
    }
}

void readercol::textchange(int index){
    switch (index) {
    case 0:
        ui->lineEdit->setPlaceholderText("ISBN:");
        break;
    case 1:
        ui->lineEdit->setPlaceholderText("书名:");
        break;
    case 2:
        ui->lineEdit->setPlaceholderText("作者:");
        break;
    case 3:
        ui->lineEdit->setPlaceholderText("出版社:");
        break;
    default:
        break;
    }
}

void readercol::on_pushButton_2_clicked()
{
    QString user_input = ui->lineEdit_2->text();
    NetworkRequestWrapper wrapper;
    QString ai_output = wrapper.sendRequest(user_input);
    QString display =cut_llm_response(ai_output);
    display+= "\n";
    ui->AI_output->insertPlainText(display);
}

/*void readercol::borrowBook(const std::string& bookId, const QDate& borrowDate, const QDate& deadline) {
    if (!currentReader) return;
    QDate deadlineDate = borrowDate.addDays(currentReader->isVip() ? 30 : 10);
    // 更新内存对象
    currentReader->borrowBook(bookId, borrowDate, deadlineDate);

    // 更新书籍状态
    auto bookIt = std::find_if(db.books.begin(), db.books.end(),
                               [&](const Book& b) { return b.getisbn() == bookId; });

    if (bookIt != db.books.end()) {
        bookIt->setAvailable(false);
    }

    // 刷新界面
    refreshBookList();
    loadAllBooks();

    // 保存到数据库
    QSqlQuery query;
    query.prepare(
        "INSERT INTO borrowed_books (reader_name, book_id, borrowtime, deadline) "
        "VALUES (:name, :book_id, :borrowtime, :deadline)");
    query.bindValue(":name", QString::fromStdString(currentReader->getName()));
    query.bindValue(":book_id", QString::fromStdString(bookId));
    query.bindValue(":borrowtime", borrowDate.toString(Qt::ISODate));
    query.bindValue(":deadline", deadlineDate.toString(Qt::ISODate));
    if (!query.exec()) {
        qDebug() << "Borrow book insert error:" << query.lastError().text();
    }
    // 更新内存对象
}*/
// readercol.cpp
void readercol::borrowBook(const std::string& isbn, const QDate& borrowDate, const QDate& deadline)
{
    if (!currentReader) return;

    // 获取LibraryDatabase实例
    LibraryDatabase& dbInstance = LibraryDatabase::getInstance();
    auto& books = dbInstance.getBook();

    // 查找书籍
    auto bookIt = std::find_if(books.begin(), books.end(),
                               [&](const Book& b) { return b.getisbn() == isbn; });
    if (bookIt == books.end()) {
        QMessageBox::warning(this, "错误", "未找到图书!");
        return;
    }

    // 更新内存对象
    currentReader->borrowBook(isbn, borrowDate, deadline);
    bookIt->setAvailable(false);

    // 保存到数据库
    if (dbInstance.saveData()) {
        refreshBookList();
        loadAllBooks();
        QMessageBox::information(this, "成功", "借阅成功!");
    } else {
        // 回滚内存操作
        currentReader->returnBook(isbn);
        bookIt->setAvailable(true);
        QMessageBox::warning(this, "错误", "保存借阅记录失败!");
    }
}
void readercol::on_pushButton_clicked()
{
    int pay = ui->spinBox->value();
    if((currentReader->getDebt()-pay)<0){
        QMessageBox::information(this,"提示！","还款金额过大，已退还超过部分！");
        currentReader->setDebt(0);
    }
    else currentReader->setDebt(currentReader->getDebt()-pay);
}



void readercol::on_lineEdit_2_editingFinished()
{

}


void readercol::on_record_bgn_clicked()
{
    if (!isRecording) {
        // 开始录音
        audioRecorder.startRecording();
        ui->record_bgn->setText("结束录音");
        isRecording = true;
        qDebug() << "录音已开始" ;
    } else {
        // 停止录音
        QString recordingFilePath = audioRecorder.getRecordingFilePath();
        audioRecorder.stopRecording();
        qDebug() << "录音已停止，文件保存到：" << recordingFilePath;
        ui->record_bgn->setText("开始录音");
        isRecording = false;
        QString transcription = getTranscription(recordingFilePath);
        ui->lineEdit_2->setText(transcription);
        qDebug() << "语音转文本成功";
        on_pushButton_2_clicked();
    }

}

