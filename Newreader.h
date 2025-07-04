#ifndef NEWREADER_H
#define NEWREADER_H

#include <QDialog>
#include <string>
#include <iostream>
#include "ui_Newreader.h"
#include <Qmessagebox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Newreader;
}
QT_END_NAMESPACE
class Newreader : public QDialog
{
    Q_OBJECT

public:
    explicit Newreader(QWidget *parent = nullptr);
    ~Newreader();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Newreader *ui;
        // 遵循命名惯例
};

#endif

