#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <QDialog>
#include <string>
#include <iostream>
#include "ui_registration.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class registration;
}
QT_END_NAMESPACE
class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:

    void on_pushButton_clicked();

    void on_reg_clicked();

private:
    Ui::registration *ui;
        // 遵循命名惯例
};

#endif // REGISTRATION_H
