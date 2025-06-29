#include "registration.h"
#include "ui_registration.h"
#include "Reader.h"
#include "database.h"
#include "readercol.h"
#include <qmessagebox.h>
#include <Newreader.h>

registration::registration(QWidget *parent)
    : QDialog(parent), ui(new Ui::registration)
{
    ui->setupUi(this);  // 初始化界面
}

registration::~registration()
{
    delete ui;
}



void registration::on_pushButton_clicked()
{
    QString text1 = ui->accout->text();
    QString text2 = ui->password->text();
    if (text1.isEmpty()||text2.isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    std::string pas = text2.toStdString();
    std::string acc = text1.toUtf8().constData();
    for(auto s:db.readers){s.setUnlocked();}
    bool exist=false;
    for(auto is:db.readers){
        if(is.getName()==acc){
            exist=true;
        }
    }
    if(!exist){
        QMessageBox::warning(this,"失败！","账号不存在！");
    }
    for(auto it=db.readers.begin();it<db.readers.end();++it){
        if(acc==it->getName()&&pas==it->getPassword()){
            if(it->getvalid()){
            it->setLocked();
            readercol rec;
            rec.exec();
            ui->accout->clear();
            ui->password->clear();
            close();}
            else QMessageBox::warning(this,"警告！","账号已被封禁！");
    }
        else if(acc==it->getName()&&pas!=it->getPassword()){
            QMessageBox::warning(this,"失败！","密码错误！");
        }
    }

}

void registration::on_reg_clicked()
{
    Newreader reg;
    reg.exec();
}

