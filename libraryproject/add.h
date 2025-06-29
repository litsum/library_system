#ifndef ADD_H
#define ADD_H

#include "database.h"
#include <iostream>
#include <vector>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class add;
}
QT_END_NAMESPACE

class add:public QDialog{
    Q_OBJECT
public:
    explicit add(QWidget *parent = nullptr);
    ~add();
signals:
    void borrow(const int);
private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add *ui;
};
#endif // ADD_H
