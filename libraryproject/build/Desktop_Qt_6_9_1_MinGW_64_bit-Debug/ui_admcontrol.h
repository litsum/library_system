/********************************************************************************
** Form generated from reading UI file 'admcontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMCONTROL_H
#define UI_ADMCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admcontrol
{
public:
    QTabWidget *addbook;
    QWidget *tab;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *resultLabel;
    QLabel *label;
    QLineEdit *isbnEdit;
    QLineEdit *publisher;
    QLineEdit *author;
    QLineEdit *name_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QWidget *tab_3;
    QLineEdit *name_2;
    QTableView *tableView_2;
    QComboBox *searchBox;
    QWidget *tab_5;
    QLineEdit *readername_2;
    QLineEdit *readername;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *tab_2;
    QLineEdit *name_3;
    QTableView *tableView_3;

    void setupUi(QDialog *admcontrol)
    {
        if (admcontrol->objectName().isEmpty())
            admcontrol->setObjectName("admcontrol");
        admcontrol->resize(625, 400);
        admcontrol->setMinimumSize(QSize(200, 300));
        admcontrol->setMaximumSize(QSize(625, 400));
        addbook = new QTabWidget(admcontrol);
        addbook->setObjectName("addbook");
        addbook->setGeometry(QRect(13, 18, 601, 361));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(380, 30, 71, 31));
        QFont font;
        font.setPointSize(10);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(118, 118, 118);\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 290, 91, 31));
        pushButton->setMinimumSize(QSize(80, 30));
        QFont font1;
        font1.setPointSize(13);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(26, 188, 156);"));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(320, 250, 71, 22));
        resultLabel = new QLabel(tab);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(170, 250, 121, 21));
        resultLabel->setFont(font);
        resultLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:5px ;"));
        resultLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 601, 341));
        label->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(199, 199, 199);"));
        isbnEdit = new QLineEdit(tab);
        isbnEdit->setObjectName("isbnEdit");
        isbnEdit->setGeometry(QRect(100, 200, 250, 30));
        isbnEdit->setMinimumSize(QSize(250, 30));
        QFont font2;
        font2.setPointSize(11);
        isbnEdit->setFont(font2);
        isbnEdit->setStyleSheet(QString::fromUtf8("border-radius:5px ;\n"
"color: rgb(139, 139, 139);\n"
"background-color: rgb(255, 255, 255);"));
        isbnEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        publisher = new QLineEdit(tab);
        publisher->setObjectName("publisher");
        publisher->setGeometry(QRect(100, 140, 250, 30));
        publisher->setMinimumSize(QSize(250, 30));
        publisher->setFont(font2);
        publisher->setStyleSheet(QString::fromUtf8("border-radius:5px ;\n"
"color: rgb(139, 139, 139);\n"
"background-color: rgb(255, 255, 255);"));
        author = new QLineEdit(tab);
        author->setObjectName("author");
        author->setGeometry(QRect(100, 90, 250, 30));
        author->setMinimumSize(QSize(250, 30));
        author->setFont(font2);
        author->setStyleSheet(QString::fromUtf8("border-radius:5px ;\n"
"color: rgb(139, 139, 139);\n"
"background-color: rgb(255, 255, 255);"));
        name_1 = new QLineEdit(tab);
        name_1->setObjectName("name_1");
        name_1->setGeometry(QRect(100, 30, 250, 30));
        name_1->setMinimumSize(QSize(250, 30));
        name_1->setFont(font2);
        name_1->setStyleSheet(QString::fromUtf8("border-radius:5px ;\n"
"gridline-color: rgb(0, 85, 255);\n"
"color: rgb(139, 139, 139);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 90, 71, 31));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(118, 118, 118);\n"
"color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(380, 140, 71, 31));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(118, 118, 118);\n"
"color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(380, 200, 71, 31));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(118, 118, 118);\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 10, 381, 311));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(222, 222, 222);"));
        addbook->addTab(tab, QString());
        label->raise();
        label_2->raise();
        pushButton_2->raise();
        pushButton->raise();
        comboBox->raise();
        resultLabel->raise();
        isbnEdit->raise();
        publisher->raise();
        author->raise();
        name_1->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab_3->setStyleSheet(QString::fromUtf8(""));
        name_2 = new QLineEdit(tab_3);
        name_2->setObjectName("name_2");
        name_2->setGeometry(QRect(10, 10, 250, 30));
        name_2->setMinimumSize(QSize(250, 30));
        name_2->setFont(font);
        name_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	alternate-background-color: rgb(255, 255, 255);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(0, 50, 621, 331));
        tableView_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(222, 222, 222);"));
        searchBox = new QComboBox(tab_3);
        searchBox->setObjectName("searchBox");
        searchBox->setGeometry(QRect(180, 14, 71, 22));
        searchBox->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(232, 232, 232);"));
        addbook->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        readername_2 = new QLineEdit(tab_5);
        readername_2->setObjectName("readername_2");
        readername_2->setGeometry(QRect(130, 100, 250, 30));
        readername_2->setMinimumSize(QSize(250, 30));
        readername_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        readername = new QLineEdit(tab_5);
        readername->setObjectName("readername");
        readername->setGeometry(QRect(130, 170, 250, 30));
        readername->setMinimumSize(QSize(250, 30));
        readername->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton_10 = new QPushButton(tab_5);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(400, 110, 56, 18));
        pushButton_11 = new QPushButton(tab_5);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(215, 237, 101, 31));
        pushButton_12 = new QPushButton(tab_5);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(400, 180, 56, 18));
        addbook->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_2->setStyleSheet(QString::fromUtf8(""));
        name_3 = new QLineEdit(tab_2);
        name_3->setObjectName("name_3");
        name_3->setGeometry(QRect(0, 10, 250, 30));
        name_3->setMinimumSize(QSize(250, 30));
        name_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        tableView_3 = new QTableView(tab_2);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(0, 40, 621, 341));
        addbook->addTab(tab_2, QString());

        retranslateUi(admcontrol);
        QObject::connect(pushButton_2, &QPushButton::clicked, name_1, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_3, &QPushButton::clicked, author, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_4, &QPushButton::clicked, publisher, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_5, &QPushButton::clicked, isbnEdit, qOverload<>(&QLineEdit::clear));

        addbook->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(admcontrol);
    } // setupUi

    void retranslateUi(QDialog *admcontrol)
    {
        admcontrol->setWindowTitle(QCoreApplication::translate("admcontrol", "\347\256\241\347\220\206\345\221\230\346\223\215\344\275\234", nullptr));
        pushButton_2->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton->setText(QCoreApplication::translate("admcontrol", "\347\241\256\350\256\244", nullptr));
        resultLabel->setText(QCoreApplication::translate("admcontrol", "\350\257\267\351\200\211\346\213\251\347\261\273\345\210\253\357\274\232", nullptr));
        label->setText(QString());
        isbnEdit->setText(QString());
        isbnEdit->setPlaceholderText(QCoreApplication::translate("admcontrol", "ISBN\357\274\232", nullptr));
        publisher->setPlaceholderText(QCoreApplication::translate("admcontrol", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        author->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\275\234\350\200\205\357\274\232", nullptr));
        name_1->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\271\246\345\220\215\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_5->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        label_2->setText(QString());
        addbook->setTabText(addbook->indexOf(tab), QCoreApplication::translate("admcontrol", "\346\267\273\345\212\240\344\271\246\347\261\215", nullptr));
        name_2->setPlaceholderText(QCoreApplication::translate("admcontrol", "\350\257\267\351\200\211\346\213\251\346\220\234\347\264\242\347\233\256\346\240\207\357\274\232", nullptr));
        addbook->setTabText(addbook->indexOf(tab_3), QCoreApplication::translate("admcontrol", "\344\271\246\347\261\215\346\225\260\346\215\256", nullptr));
        readername_2->setPlaceholderText(QCoreApplication::translate("admcontrol", "\350\247\243\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        readername->setPlaceholderText(QCoreApplication::translate("admcontrol", "\345\260\201\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        pushButton_10->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_11->setText(QCoreApplication::translate("admcontrol", "\347\241\256\350\256\244", nullptr));
        pushButton_12->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        addbook->setTabText(addbook->indexOf(tab_5), QCoreApplication::translate("admcontrol", "\350\257\273\350\200\205\347\212\266\346\200\201\346\216\247\345\210\266", nullptr));
        name_3->setPlaceholderText(QCoreApplication::translate("admcontrol", "\350\257\267\351\200\211\346\213\251\346\220\234\347\264\242\347\233\256\346\240\207\357\274\232", nullptr));
        addbook->setTabText(addbook->indexOf(tab_2), QCoreApplication::translate("admcontrol", "\350\257\273\350\200\205\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admcontrol: public Ui_admcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMCONTROL_H
