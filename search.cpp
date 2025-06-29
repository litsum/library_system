#include <QtWidgets>
#include <string>
#include "search.h"
#include "database.h"
#include "add.h"

FindDialog::FindDialog(QWidget* parent) : QDialog(parent) {
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    deleteButton = new QPushButton(tr("delete"));

    // 连接文本输入框与允许查找函数
    connect(lineEdit, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableFindButton(const QString&)));
    // 连接查找槽与点击函数
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    // 连接关闭槽与关闭函数
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));
    // 连接删除槽与删除函数
    connect(deleteButton, SIGNAL(clicked()),
            this, SLOT(deletetext()));

    // 布局修正
    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addWidget(deleteButton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked() {
    QString text = lineEdit->text();
    std::string name=text.toStdString();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    }
    else {
        emit findNext(text, cs);
    }

    for(auto it=db.books.begin();it<db.books.end();++it){
        if(it->getName()==name)
        {
            std::cout<<it->getName()<<"已找到"<<std::endl;
            add dialog;
            connect(&dialog,&add::borrow,this,&FindDialog::choice);
            if (dialog.exec() == QDialog::Accepted) {}
        }
        }
    for(auto it=db.books.begin();it<db.books.end();++it){
        if(it->getName()==name)
        {
            std::cout<<it->getName()<<"已找到"<<std::endl;
            add dialog;
            connect(&dialog,&add::borrow,this,&FindDialog::choice);
            if (dialog.exec() == QDialog::Accepted) {}
    }
}
}
void FindDialog::deletetext() {
    lineEdit->clear();
}

void FindDialog::enableFindButton(const QString& text) {
    findButton->setEnabled(!text.isEmpty());
}

void FindDialog::choice(const int a){
    QString text = lineEdit->text();
    std::string name=text.toStdString();
    if(a){
    for(auto is=db.readers.begin();is<db.readers.end();++is){
            if(is->isLocked()){
                is->borrowBook(name);
                QMessageBox::information(this,"成功","书籍已成功添加！");}
    }
    }
}
