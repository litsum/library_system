#include "delete_.h"
#include "ui_delete_.h"
#include "QMessageBox"

delete_::delete_(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_)
{
    ui->setupUi(this);
}

delete_::~delete_()
{
    delete ui;
}

void delete_::on_pushButton_2_clicked()
{
    QString name = ui->name->text().toUtf8();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    else  {
        for(auto it=db.book1.begin();it<db.book1.end();++it){
            if(it->getName()==name){
                emit bookdelete1(it);
                return;
            }
        }
        for(auto it=db.book2.begin();it<db.book2.end();++it){
            if(it->getName()==name){
                emit bookdelete2(it);
                return;
            }
        }
        QMessageBox::information(this,"失败","书籍未找到！");
        accept();  // 关闭对话框并返回Accepted状态
    }
}
