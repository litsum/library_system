#include "admcontrol.h"
#include "ui_admcontrol.h"
#include "book.h"
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include <QMenu>
#include <QComboBox>
#include "find.h"
#include "librarydatabase.h"

admcontrol::admcontrol(QWidget *parent)
    : QDialog(parent), ui(new Ui::admcontrol), _model(new QStandardItemModel(this)),
    _rmodel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    isbnEdit = findChild<QLineEdit*>("isbnEdit"); // 获取ISBN输入框
    refreshBookTable();
    refreshreader();

    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者","出版社","类型","状态"});
    _rmodel->setHorizontalHeaderLabels({"账号","密码","状态","等级","欠款"});

    //下拉选择
    ui->comboBox->addItem("哲学");
    ui->comboBox->addItem("艺术");
    ui->comboBox->addItem("自然科学");
    ui->comboBox->addItem("社会科学");
    ui->comboBox->addItem("教育");
    ui->comboBox->addItem("文学");
    // 可选：设置搜索列
    ui->searchBox->addItem("ISBN", 0);
    ui->searchBox->addItem("书名", 1);
    ui->searchBox->addItem("作者", 2);
    ui->searchBox->addItem("出版社", 3);
    ui->searchBox->addItem("种类",4);

    // 关联到视图4
    BookSearchProxyModel *proxyModel = new BookSearchProxyModel(this);
    proxyModel->setSourceModel(_model);
    ui->tableView_2->setModel(proxyModel);
    ui->tableView_2->setSortingEnabled(true);

    // 连接搜索框
    connect(ui->name_2, &QLineEdit::textChanged,
            [proxyModel](const QString &text) {
                proxyModel->setSearchPrefix(text);
            });
    connect(ui->searchBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [proxyModel](int index) {
                proxyModel->setSearchColumn(index);
            });
    connect(ui->searchBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,
            &admcontrol::textchange);

    //右键点击功能
    ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_2, &QTableView::customContextMenuRequested, [this, proxyModel](const QPoint &pos){
        QMenu menu;
        QAction *deleteAction = menu.addAction("删除图书");
        if (deleteAction == menu.exec(ui->tableView_2->viewport()->mapToGlobal(pos))) {
            QModelIndex index = ui->tableView_2->indexAt(pos);
            if (index.isValid()) {
                // 映射到源模型索引
                QModelIndex sourceIndex = proxyModel->mapToSource(index);
                if (sourceIndex.isValid()) {
                    QString name = _model->item(sourceIndex.row(), 1)->text();
                    if (db.deletebook(name)) {
                        _model->removeRow(sourceIndex.row());
                        //添加删除数据库内书籍逻辑
                        QMessageBox::information(this, "成功", "图书已删除");
                    } else {
                        QMessageBox::warning(this, "错误", "删除图书失败");
                    }
                }
            }
        }
    });
    // 初始化读者数据表格
    ui->tableView->setModel(_rmodel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->show();

}
admcontrol::~admcontrol()
{
    delete ui;
}

void admcontrol::refreshBookTable()
{
    _model->removeRows(0, _model->rowCount());
    int row =0;
    for(auto is=db.books.begin();is!=db.books.end();++is){
        QList<QStandardItem*> rowItems;
        // ISBN
        QString isbn = QString::fromStdString(is->getisbn());
        rowItems << new QStandardItem(isbn);

        // 书名
        QString name = QString::fromStdString(is->getName());
        rowItems << new QStandardItem(name);

        // 作者
        QString author = QString::fromStdString(is->getAuthor());
        rowItems << new QStandardItem(author);

        // 出版社
        QString publisher = QString::fromStdString(is->getPublisher());
        rowItems << new QStandardItem(publisher);

        // 类型
        QString type = QString::fromStdString(is->getType());
        rowItems << new QStandardItem(type);
        // 状态（需要根据借阅记录计算）
        /*bool available = true;
        QSqlQuery borrowQuery;
        borrowQuery.prepare("SELECT COUNT(*) FROM borrowed_books WHERE book_id = :isbn");
        borrowQuery.bindValue(":isbn", isbn);
        if (borrowQuery.exec() && borrowQuery.next()) {
            available = (borrowQuery.value(0).toInt() == 0);
        }*/

        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(is->isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(is->isAvailable() ? "可借阅" : "已借出");
        rowItems << statusItem;
        _model->appendRow(rowItems);
        row++;
    }

}

void admcontrol::on_pushButton_clicked()
{
    QString name = ui->name_1->text().toUtf8();
    QString author = ui->author->text();
    QString publisher = ui->publisher->text();
    QString isbn = isbnEdit->text(); // 获取ISBN输入
    QString type = ui->resultLabel->text();

    if (name.isEmpty() || author.isEmpty() || publisher.isEmpty() ||
        isbn.isEmpty() || type == "请选择类别：") {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    Book newBook(name.toStdString(), author.toStdString(),
                 publisher.toStdString(),isbn.toStdString(),type.toStdString());
    // 保存到数据库
    QSqlQuery query(LibraryDatabase::getInstance().getDatabase());
    query.prepare("INSERT INTO books (isbn, name, author, type, publisher) "
                  "VALUES (:isbn, :name, :author, :type, :publisher)");
    query.bindValue(":isbn", isbn);
    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":type", type);
    query.bindValue(":publisher", publisher);

    if (!query.exec()) {
        QMessageBox::warning(this, "错误", "添加书籍失败: " + query.lastError().text());
        return;
    }
    db.books.push_back(newBook);

    QMessageBox::information(this, "成功", "书籍添加成功！");
    ui->name_1->clear();
    ui->author->clear();
    ui->publisher->clear();
    isbnEdit->clear();
    refreshBookTable();
}


void admcontrol::textchange(int index){
    switch (index) {
    case 0:
        ui->name_2->setPlaceholderText("ISBN:");
        break;
    case 1:
        ui->name_2->setPlaceholderText("书名:");
        break;
    case 2:
        ui->name_2->setPlaceholderText("作者:");
        break;
    case 3:
        ui->name_2->setPlaceholderText("出版社:");
        break;
    case 4:
        ui->name_2->setPlaceholderText("种类：");
        break;
    default:
        break;
    }
}

void admcontrol::on_comboBox_activated(int index)
{
    QString text = ui->comboBox->itemText(index);
    QString result = QString("%1").arg(text);
    ui->resultLabel->setText(result);
}

void admcontrol::refreshreader(){
    _rmodel->removeRows(0, _rmodel->rowCount());
    int row=0;
    for(auto is=db.readers.begin();is!=db.readers.end();++is) {
        QList<QStandardItem*> rowItems;

        // 账号
        QString acc = QString::fromStdString(is->getName());
        rowItems << new QStandardItem(acc);

        // 密码
        QString pas = QString::fromStdString(is->getPassword());
        rowItems << new QStandardItem(pas);

        // 状态
        int valid = is->getvalid();
        QStandardItem *statusItem_ = new QStandardItem();
        statusItem_->setText(valid ? "正常" : "已封禁");
        rowItems << statusItem_;

        // 等级
        bool isVIP = is->getvip();
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setText(isVIP ? "VIP用户" : "普通用户");
        rowItems << statusItem;
        // 欠款
        int debt = is->getDebt();
        QString Debt = QString::number(debt);
        rowItems << new QStandardItem(Debt);

        _rmodel->appendRow(rowItems);
        row++;
    }
}


void admcontrol::on_pushButton_11_clicked()
{
    QString ban_ = ui->readername->text();
    QString recover_ = ui->readername_2->text();
    if (ban_.isEmpty() && recover_.isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    std::string _ban = ban_.toUtf8().toStdString();
    std::string _recover = recover_.toUtf8().toStdString();
    for(auto is=db.readers.begin();is!=db.readers.end();++is){
        if(is->getName()==_ban){
            is->ban();
            QSqlQuery query(LibraryDatabase::getInstance().getDatabase());
            query.prepare("UPDATE readers SET valid = 0 WHERE name = :name");
            query.bindValue(":name", ban_);
            QMessageBox::information(this,"成功!","封禁成功！");
            refreshreader();
            break;
        }

    }
    for(auto is=db.readers.begin();is!=db.readers.end();++is){
        if(is->getName()==_recover){
            is->recover();
            QSqlQuery query(LibraryDatabase::getInstance().getDatabase());
            query.prepare("UPDATE readers SET valid = 1 WHERE name = :name");
            query.bindValue(":name", recover_);
            QMessageBox::information(this,"成功!","解封成功！");
            refreshreader();
            break;
        }
    }
}
