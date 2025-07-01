#include "admcontrol.h"
#include "ui_admcontrol.h"
#include "book.h"
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include <QMenu>
#include <QComboBox>
#include "find.h"

admcontrol::admcontrol(QWidget *parent)
    : QDialog(parent), ui(new Ui::admcontrol)
{
    ui->setupUi(this);
    /*for(auto is=db.books.begin();is<db.books.end();++is){
        QString bo=QString::fromStdString(is->getName());
        booklist.append(bo);
    }
    model= new QStringListModel(this); //创建数据模型
    model->setStringList(booklist); //初始化数据
    ui->listView->setModel(model); //设置数据模型
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);*/

    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者","出版社","状态"});
    int row=0;
    for(auto is=db.books.begin();is<db.books.end(); ++row,++is) {
        // 获取图书数据 (根据你的实际数据结构调整)
        // 创建行数据
        QList<QStandardItem*> rowItems;
        // ISBN (第0列)
        QString isbn = QString::fromStdString(is->getISBN());
        QStandardItem *isbnItem = new QStandardItem(isbn);
        isbnItem->setEditable(false); // ISBN通常不可编辑
        // 书名 (第1列)
        QString name = QString::fromStdString(is->getName());
        QStandardItem *nameItem = new QStandardItem(name);
        // 作者 (第2列)
        QString author = QString::fromStdString(is->getAuthor());
        QStandardItem *authorItem = new QStandardItem(author);
        // 出版社 (第3列)
        QString publisher = QString::fromStdString(is->getPublisher());
        QStandardItem *publisherItem = new QStandardItem(publisher);
        // 状态 (第4列) - 复选框
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(is->isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(is->isAvailable() ? "可借阅" : "已借出"); // 可选的文本显示
        // 添加到行
        rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;
        // 添加行到模型
        _model->appendRow(rowItems);
    }
        //右键点击功能
        ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(ui->tableView_2, &QTableView::customContextMenuRequested, [&](const QPoint &pos){
            QMenu menu;
            QAction *deleteAction = menu.addAction("删除图书");
            if (deleteAction == menu.exec(ui->tableView_2->viewport()->mapToGlobal(pos))) {
                QModelIndex index = ui->tableView_2->indexAt(pos);
                if (index.isValid()) {
                    QString name = _model->index(index.row(), 1).data().toString();
                    db.deletebook(name);
                    _model->removeRow(index.row());
                    refreshBookTable();
                }
            }
        });

        //下拉选择
        ui->comboBox->addItem("哲学");
        ui->comboBox->addItem("艺术");
        ui->comboBox->addItem("自然科学");
        ui->comboBox->addItem("社会科学");
        ui->comboBox->addItem("教育");
        ui->comboBox->addItem("文学");

        refreshBookTable();
    // 关联到视图
    ui->tableView->setModel(_model);
    ui->tableView_2->setModel(_model);
}
admcontrol::~admcontrol()
{
    delete ui;  // 释放内存
    delete _model;
}

void admcontrol::refreshBookTable()
{
    _model->removeRows(0, _model->rowCount());

    int row = 0;
    for(auto is = db.books.begin(); is != db.books.end(); ++is) {
        QList<QStandardItem*> rowItems;

        // ISBN
        QString isbn = QString::fromStdString(is->getISBN());
        QStandardItem *isbnItem = new QStandardItem(isbn);
        isbnItem->setEditable(false);

        // 书名
        QString name = QString::fromStdString(is->getName());
        QStandardItem *nameItem = new QStandardItem(name);

        // 作者
        QString author = QString::fromStdString(is->getAuthor());
        QStandardItem *authorItem = new QStandardItem(author);

        // 出版社
        QString publisher = QString::fromStdString(is->getPublisher());
        QStandardItem *publisherItem = new QStandardItem(publisher);

        // 状态
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(is->isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(is->isAvailable() ? "可借阅" : "已借出");
        statusItem->setEditable(false);

        rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;
        _model->appendRow(rowItems);
        row++;
    }
}

void admcontrol::on_pushButton_clicked()
{
    QString name = ui->name_1->text().toUtf8();
    QString author = ui->author->text();
    QString publisher = ui->publisher->text();
    QString isbn = ui->resultLabel->text();

    if (name.isEmpty() || author.isEmpty() || publisher.isEmpty() || isbn=="请选择类别：") {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    Book newBook(name.toStdString(), author.toStdString(), publisher.toStdString(),isbn.toStdString());
    db.books.push_back(newBook);
    QMessageBox::information(this, "成功", "书籍添加成功！");
    ui->name_1->clear();
    ui->author->clear();
    ui->publisher->clear();
    refreshBookTable();
}




void admcontrol::on_pushButton_6_clicked()
{
    QString name = ui->name_2->text().toUtf8();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    else  {
        // 创建原始模型
        QStandardItemModel *bookModel = new QStandardItemModel(this);
        bookModel->setHorizontalHeaderLabels({"ISBN", "书名", "作者", "出版社","状态"});

        bookModel->removeRows(0, bookModel->rowCount());

        int row = 0;
        for(auto is = db.books.begin(); is != db.books.end(); ++is) {
            QList<QStandardItem*> rowItems;

            // ISBN
            QString isbn = QString::fromStdString(is->getISBN());
            QStandardItem *isbnItem = new QStandardItem(isbn);
            isbnItem->setEditable(false);

            // 书名
            QString name = QString::fromStdString(is->getName());
            QStandardItem *nameItem = new QStandardItem(name);

            // 作者
            QString author = QString::fromStdString(is->getAuthor());
            QStandardItem *authorItem = new QStandardItem(author);

            // 出版社
            QString publisher = QString::fromStdString(is->getPublisher());
            QStandardItem *publisherItem = new QStandardItem(publisher);

            // 状态
            QStandardItem *statusItem = new QStandardItem();
            statusItem->setCheckable(true);
            statusItem->setCheckState(is->isAvailable() ? Qt::Checked : Qt::Unchecked);
            statusItem->setText(is->isAvailable() ? "可借阅" : "已借出");
            statusItem->setEditable(false);

            rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;
            bookModel->appendRow(rowItems);
            row++;
        }
        // 创建代理模型
        BookSearchProxyModel *proxyModel = new BookSearchProxyModel(this);
        proxyModel->setSourceModel(bookModel);

        // 设置到TableView
        ui->tableView_2->setModel(proxyModel);
        ui->tableView_2->setSortingEnabled(true);

        // 连接搜索框
        connect(ui->name_2, &QLineEdit::textChanged,
                [proxyModel](const QString &text) {
                    proxyModel->setSearchPrefix(text);
                });

        // 可选：设置搜索列
        QComboBox *searchColumnCombo = new QComboBox(this);
        searchColumnCombo->addItem("ISBN", 0);
        searchColumnCombo->addItem("书名", 1);
        searchColumnCombo->addItem("作者", 2);
        searchColumnCombo->addItem("出版社", 3);
        searchColumnCombo->addItem("状态", 4);

        connect(searchColumnCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                [proxyModel](int index) {
                    proxyModel->setSearchColumn(index);
                });
    }
    QMessageBox::information(this,"失败","书籍未找到！");
    ui->name_2->clear();
}


void admcontrol::on_pushButton_11_clicked()
{
    QString rename = ui->readername->text().toUtf8();
    QString rename2 = ui->readername_2->text().toUtf8();
    if (!rename.isEmpty()) {
        for(auto it=db.readers.begin();it<db.readers.end();it++){
            if(it->getName()==rename){
                it->ban();
                return;
            }
            else QMessageBox::information(this,"失败","读者未找到！");
        }
        if(!rename2.isEmpty()){
            for(auto it=db.readers.begin();it<db.readers.end();it++){
                if(it->getName()==rename){
                    it->ban();
                    return;}
                else QMessageBox::information(this,"失败","读者未找到！");
            }
        }
        QMessageBox::warning(this, "错误", "请填写所有字段！");
    }
}




void admcontrol::on_comboBox_activated(int index)
{
    QString text = ui->comboBox->itemText(index);
    QString result = QString("%1").arg(text);
    ui->resultLabel->setText(result);
}

