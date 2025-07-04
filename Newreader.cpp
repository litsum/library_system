#include <Newreader.h>
#include "ui_Newreader.h"
#include "Reader.h"
#include "database.h"

Newreader::Newreader(QWidget *parent)
    : QDialog(parent), ui(new Ui::Newreader)
{
    ui->setupUi(this);  // 初始化界面
}

Newreader::~Newreader()
{
    delete ui;
}



void Newreader::on_pushButton_2_clicked()
{
    QString text1 = ui->lineEdit->text();
    QString text2 = ui->lineEdit_2->text();
    if (text1.isEmpty()||text2.isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    std::string pas = text1.toStdString();
    std::string acc = text2.toUtf8().constData();
    db.readers.push_back(reader(acc,pas));
    close();
}
