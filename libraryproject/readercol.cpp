#include "readercol.h"
#include "ui_readercol.h"
#include "book.h"
#include "database.h"
#include "search.h"
#include <QMessageBox>
#include <QMenu>


readercol::readercol(QWidget *parent)
    : QDialog(parent), ui(new Ui::readercol)
{
    ui->setupUi(this);  // 初始化界面
    for(auto is=db.readers.begin();is<db.readers.end();++is){
        if(is->isLocked()){
        model= new QStringListModel(this); //创建数据模型
        model->setStringList(is->borrowbooklist()); //初始化数据
        ui->listView->setModel(model); //设置数据模型
        ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        // 书架视图

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
            /*QStandardItem *statusItem = new QStandardItem();
            statusItem->setCheckable(true);
            statusItem->setCheckState(book.isAvailable ? Qt::Checked : Qt::Unchecked);
            statusItem->setText(book.isAvailable ? "可借阅" : "已借出"); // 可选的文本显示*/
            QStandardItem *statusItem = new QStandardItem();
            statusItem->setCheckable(true);
            statusItem->setCheckState(row % 2 ? Qt::Checked : Qt::Unchecked);
            // 添加到行
            rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;

            // 添加行到模型
            _model->appendRow(rowItems);

        }

        // 关联到视图
        ui->tableView->setModel(_model);

}
}
}
readercol::~readercol()
{
    delete ui;  // 释放内存
}


void readercol::on_borrowbook_clicked()
{
    FindDialog  fi;
    fi.exec();
}



void readercol::handleBookdelete1(const std::vector<Book>::iterator it){
    for(auto is=db.readers.begin();is<db.readers.end();++is){
        if(is->isLocked()){
            is->returnBook(it->getName());
            QMessageBox::information(this, "成功", "书籍删除成功！");}
    }
}


void readercol::on_pay_clicked()
{
    for(auto is=db.readers.begin();is<db.readers.end();++is){
        if(is->isLocked()){
            std::cout<<"您当前的欠款为："<<is->getDebt()<<std::endl;}

    }

}




void readercol::on_pushButton_2_clicked()
{
    QString content = ui->lineEdit_2->text();
    std::string user_input = content.toUtf8().toStdString();
}

