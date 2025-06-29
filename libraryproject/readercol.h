#ifndef READERCOL_H
#define READERCOL_H
#include <QDialog>
#include <string>
#include <iostream>
#include "database.h"
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
namespace Ui {
class readercol;
}
QT_END_NAMESPACE
class readercol : public QDialog
{
    Q_OBJECT

public:
    explicit readercol(QWidget *parent = nullptr);
    ~readercol();

private slots:

    void handleBookdelete1(const std::vector<Book>::iterator it);
    void on_borrowbook_clicked();
    void on_pay_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::readercol *ui;
    QStringListModel *model;
    QStandardItemModel *_model = new QStandardItemModel(0, 5);
    QTableView *tableView = new QTableView;
};


#endif // READERCOL_H
