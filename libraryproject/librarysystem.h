#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <QWidget>
#include "librarydatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LibrarySystem;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_ad_clicked();
    void on_re_clicked();

private:
    Ui::LibrarySystem *ui;
};
#endif // LIBRARYSYSTEM_H
