#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog {
    Q_OBJECT
public:
    explicit FindDialog(QWidget* parent = nullptr);
signals:
    void findNext(const QString& str, Qt::CaseSensitivity cs);
    void findPrevious(const QString& str, Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void deletetext();
    void enableFindButton(const QString& text);
    void choice(const int);
private:

    QLabel* label;
    QLineEdit* lineEdit;
    QCheckBox* caseCheckBox;
    QCheckBox* backwardCheckBox;
    QPushButton* findButton;
    QPushButton* closeButton;
    QPushButton* deleteButton;
};
#endif


