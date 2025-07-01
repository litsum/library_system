#ifndef WARNING_H
#define WARNING_H
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class warning;
}
QT_END_NAMESPACE
class warning : public QDialog
{
    Q_OBJECT

public:
    explicit warning(QWidget *parent = nullptr);
    ~warning();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::warning *ui;   // 遵循命名惯例
};

#endif // WARNING_H
