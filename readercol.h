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
#include "audio_recorder.h"

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
    void refreshBookList();
    void on_pushButton_2_clicked();
    void textchange(int index);
    void on_pushButton_clicked();

    void on_lineEdit_2_editingFinished();

    void on_record_bgn_clicked();

private:
    Ui::readercol *ui;
    QStringListModel *model;
    QStandardItemModel *_model = new QStandardItemModel(0, 7);
    QTableView *tableView = new QTableView;
    reader *currentReader = nullptr;  // 当前登录的读者指针

    AudioRecorder audioRecorder;
    bool isRecording;
    // 辅助方法
    QString cut_llm_response(QString ai_output);
    void loadAllBooks();
    void showContextMenu(const QPoint &pos);
    void showReturnMenu(const QPoint &pos);
    void borrowBook(const std::string& bookId, const QDate& borrowDate, const QDate& deadline);
};


#endif // READERCOL_H
