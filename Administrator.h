
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Administrator;
}
QT_END_NAMESPACE
class Administrator : public QDialog
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private slots:

    void on_next_clicked();

private:
    Ui::Administrator *ui;   // 遵循命名惯例
};

#endif // ADMINISTRATOR_H
