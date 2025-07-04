#include <warning.h>
#include "ui_warning.h"
#include <qmessagebox.h>
#include "database.h"
warning::warning(QWidget *parent)
    : QDialog(parent), ui(new Ui::warning)
{
    ui->setupUi(this);  // 初始化界面
}

warning::~warning()
{
    delete ui;  // 释放内存
}


void warning::on_pushButton_clicked()
{
    if(db.saveData()){
        QMessageBox::information(this,"成功","保存成功！");
    }
    else QMessageBox::critical(this,"失败","保存失败！");
    close();
}


void warning::on_pushButton_2_clicked()
{
    close();
}

