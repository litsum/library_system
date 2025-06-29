#ifndef DELETE__H
#define DELETE__H

#include "database.h"
#include <iostream>
#include <vector>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class delete_;
}
QT_END_NAMESPACE

class delete_:public QDialog{
    Q_OBJECT
public:
    explicit delete_(QWidget *parent = nullptr);
    ~delete_();
signals:
    void bookdelete(const std::vector<Book>::iterator it);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::delete_ *ui;
};
#endif // DELETE__H
