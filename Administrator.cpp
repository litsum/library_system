#include "Administrator.h"
#include "ui_Administrator.h"
#include "admcontrol.h"
#include <qmessagebox.h>
Administrator::Administrator(QWidget *parent)
    : QDialog(parent), ui(new Ui::Administrator)
{
    ui->setupUi(this);  // 初始化界面
}

Administrator::~Administrator()
{
    delete ui;  // 释放内存
}


/*void Administrator::on_next_clicked()
{
    QString adc= ui->adaccout->text();
    QString adp= ui->adpassword->text();
    if(adc.toStdString()=="administrator"&&adp.toStdString()=="123456"){
        admcontrol adm;
        adm.exec();}
    else{
        QMessageBox::warning(this, "错误", "账号或密码错误！");
    }
}*/

void Administrator::on_next_clicked()
{

        admcontrol adm;
        adm.exec();
}







