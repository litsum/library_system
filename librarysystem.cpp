#include "librarysystem.h"
#include "administrator.h"
#include "Reader.h"
#include "Newreader.h"
#include "registration.h"
#include "ui_librarysystem.h"
#include "database.h"
#include "warning.h"// 假设使用单例数据库

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibrarySystem)
{
    ui->setupUi(this); // 先设置UI，再加载数据

    if (!db.loadData()) {
        QMessageBox::warning(this, "数据加载", "无法加载数据库文件，将使用空数据库。");
    }
}

Widget::~Widget()
{
    delete ui;
    warning w;
    w.exec();
}

void Widget::on_ad_clicked()
{
    Administrator ad(this); // 传递父窗口指针
    if (ad.exec() == QDialog::Accepted) {
        // 处理对话框接受后的逻辑
    }
}



void Widget::on_re_clicked()
{
    registration re(this);
    re.exec();
}

