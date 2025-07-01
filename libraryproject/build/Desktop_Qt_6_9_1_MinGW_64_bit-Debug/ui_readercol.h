/********************************************************************************
** Form generated from reading UI file 'readercol.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERCOL_H
#define UI_READERCOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readercol
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QListView *listView;
    QWidget *tab_2;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QWidget *tab_3;
    QWidget *tab_4;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *readercol)
    {
        if (readercol->objectName().isEmpty())
            readercol->setObjectName("readercol");
        readercol->resize(599, 374);
        tabWidget = new QTabWidget(readercol);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 591, 371));
        tab = new QWidget();
        tab->setObjectName("tab");
        listView = new QListView(tab);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 0, 591, 341));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 20, 591, 321));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 0, 231, 21));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 0, 60, 22));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        lineEdit_2 = new QLineEdit(tab_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(50, 50, 221, 21));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 50, 56, 18));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(readercol);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(readercol);
    } // setupUi

    void retranslateUi(QDialog *readercol)
    {
        readercol->setWindowTitle(QCoreApplication::translate("readercol", "\350\257\273\350\200\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("readercol", "\344\271\246\346\236\266", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("readercol", "\350\257\267\350\276\223\345\205\245\344\271\246\345\220\215\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("readercol", "\344\271\246\345\237\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("readercol", "\350\264\246\346\210\267\347\212\266\346\200\201", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("readercol", "\350\257\267\350\276\223\345\205\245\345\206\205\345\256\271\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("readercol", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("readercol", "AI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readercol: public Ui_readercol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERCOL_H
