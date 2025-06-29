#ifndef READERCOL_H
#define READERCOL_H
#include <QDialog>
#include <string>
#include <iostream>
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include "database.h"

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
    void on_borrowbook_clicked();
    void on_pay_clicked();
    void refreshBookList();
    void on_pushButton_2_clicked();

private:
    Ui::readercol *ui;
    QStringListModel *model;
    QStandardItemModel *_model = new QStandardItemModel(0, 5);
    QTableView *tableView = new QTableView;
    reader *currentReader = nullptr;  // 当前登录的读者指针

    // 辅助方法
    void loadAllBooks();
    void showContextMenu(const QPoint &pos);
    void showReturnMenu(const QPoint &pos);
};


#endif // READERCOL_H
