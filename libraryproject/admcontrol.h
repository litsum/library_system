#ifndef ADMCONTROL_H
#define ADMCONTROL_H

#include <QDialog>
#include <qwidget.h>
#include <string>
#include <iostream>
#include "librarydatabase.h"
#include <QStringListModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QComboBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class admcontrol;
}
QT_END_NAMESPACE
class admcontrol : public QDialog
{
    Q_OBJECT

public:
    explicit admcontrol(QWidget *parent = nullptr);
    ~admcontrol();

private slots:
    void on_pushButton_clicked();
    void refreshBookTable();
    void on_comboBox_activated(int index);
    void textchange(int index);
private:
    Ui::admcontrol *ui;
    QStringList booklist;
    QStringListModel *model;
    QStandardItemModel *_model;
    QTableView *tableView = new QTableView;
    QTableView *tableView_2 = new QTableView;
    QLineEdit *isbnEdit;
};

#endif
