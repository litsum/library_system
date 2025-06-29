#include "add.h"
#include "ui_add.h"
#include "QMessageBox"

add::add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}



void add::on_pushButton_2_clicked()
{
    close();
}


void add::on_pushButton_clicked()
{
    emit borrow(1);
}

