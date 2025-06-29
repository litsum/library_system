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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admcontrol
{
public:
    QTabWidget *addbook;
    QWidget *tab;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_1;
    QLineEdit *author;
    QLineEdit *publisher;
    QLineEdit *ISBN;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QLineEdit *name_2;
    QPushButton *pushButton_6;
    QListView *listView;
    QWidget *tab_4;
    QLineEdit *name_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *tab_5;
    QLineEdit *readername_2;
    QLineEdit *readername;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *tab_6;
    QTableView *tableView;

    void setupUi(QDialog *admcontrol)
    {
        if (admcontrol->objectName().isEmpty())
            admcontrol->setObjectName("admcontrol");
        admcontrol->resize(625, 400);
        admcontrol->setMinimumSize(QSize(625, 300));
        admcontrol->setMaximumSize(QSize(625, 400));
        addbook = new QTabWidget(admcontrol);
        addbook->setObjectName("addbook");
        addbook->setGeometry(QRect(0, 0, 621, 401));
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(430, 100, 56, 18));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(430, 220, 56, 18));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(430, 160, 56, 18));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(29, 9, 371, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name_1 = new QLineEdit(verticalLayoutWidget);
        name_1->setObjectName("name_1");
        name_1->setMinimumSize(QSize(250, 30));
        name_1->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));

        verticalLayout->addWidget(name_1, 0, Qt::AlignmentFlag::AlignHCenter);

        author = new QLineEdit(verticalLayoutWidget);
        author->setObjectName("author");
        author->setMinimumSize(QSize(250, 30));
        author->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));

        verticalLayout->addWidget(author, 0, Qt::AlignmentFlag::AlignHCenter);

        publisher = new QLineEdit(verticalLayoutWidget);
        publisher->setObjectName("publisher");
        publisher->setMinimumSize(QSize(250, 30));
        publisher->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));

        verticalLayout->addWidget(publisher, 0, Qt::AlignmentFlag::AlignHCenter);

        ISBN = new QLineEdit(verticalLayoutWidget);
        ISBN->setObjectName("ISBN");
        ISBN->setMinimumSize(QSize(250, 30));
        ISBN->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));

        verticalLayout->addWidget(ISBN, 0, Qt::AlignmentFlag::AlignHCenter);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignmentFlag::AlignHCenter);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 50, 56, 18));
        addbook->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        name_2 = new QLineEdit(tab_3);
        name_2->setObjectName("name_2");
        name_2->setGeometry(QRect(10, 10, 250, 30));
        name_2->setMinimumSize(QSize(250, 30));
        name_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(270, 20, 56, 18));
        listView = new QListView(tab_3);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 40, 611, 331));
        addbook->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        name_3 = new QLineEdit(tab_4);
        name_3->setObjectName("name_3");
        name_3->setGeometry(QRect(120, 120, 250, 30));
        name_3->setMinimumSize(QSize(250, 30));
        name_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(420, 130, 56, 18));
        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(180, 210, 151, 30));
        pushButton_9->setMinimumSize(QSize(150, 30));
        addbook->addTab(tab_4, QString());
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
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tableView = new QTableView(tab_6);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 611, 371));
        addbook->addTab(tab_6, QString());

        retranslateUi(admcontrol);
        QObject::connect(pushButton_2, &QPushButton::clicked, name_1, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_3, &QPushButton::clicked, author, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_4, &QPushButton::clicked, publisher, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_5, &QPushButton::clicked, ISBN, qOverload<>(&QLineEdit::clear));

        addbook->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(admcontrol);
    } // setupUi

    void retranslateUi(QDialog *admcontrol)
    {
        admcontrol->setWindowTitle(QCoreApplication::translate("admcontrol", "admcontrol", nullptr));
        pushButton_3->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_5->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        name_1->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\271\246\345\220\215\357\274\232", nullptr));
        author->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\275\234\350\200\205\357\274\232", nullptr));
        publisher->setPlaceholderText(QCoreApplication::translate("admcontrol", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        ISBN->setPlaceholderText(QCoreApplication::translate("admcontrol", "ISBN\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("admcontrol", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        addbook->setTabText(addbook->indexOf(tab), QCoreApplication::translate("admcontrol", "\346\267\273\345\212\240\344\271\246\347\261\215", nullptr));
        name_2->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\271\246\345\220\215\357\274\232", nullptr));
        pushButton_6->setText(QCoreApplication::translate("admcontrol", "\346\220\234\347\264\242", nullptr));
        addbook->setTabText(addbook->indexOf(tab_3), QCoreApplication::translate("admcontrol", "\345\210\240\351\231\244\344\271\246\347\261\215\357\274\210\345\210\227\350\241\250\345\274\217\357\274\211", nullptr));
        name_3->setPlaceholderText(QCoreApplication::translate("admcontrol", "\344\271\246\345\220\215\357\274\232", nullptr));
        pushButton_8->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_9->setText(QCoreApplication::translate("admcontrol", "\347\241\256\350\256\244", nullptr));
        addbook->setTabText(addbook->indexOf(tab_4), QCoreApplication::translate("admcontrol", "\346\237\245\346\211\276\344\271\246\347\261\215", nullptr));
        readername_2->setPlaceholderText(QCoreApplication::translate("admcontrol", "\350\247\243\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        readername->setPlaceholderText(QCoreApplication::translate("admcontrol", "\345\260\201\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        pushButton_10->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        pushButton_11->setText(QCoreApplication::translate("admcontrol", "\347\241\256\350\256\244", nullptr));
        pushButton_12->setText(QCoreApplication::translate("admcontrol", "\346\270\205\347\251\272", nullptr));
        addbook->setTabText(addbook->indexOf(tab_5), QCoreApplication::translate("admcontrol", "\350\257\273\350\200\205\347\212\266\346\200\201\346\216\247\345\210\266", nullptr));
        addbook->setTabText(addbook->indexOf(tab_6), QCoreApplication::translate("admcontrol", "\344\271\246\347\261\215\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admcontrol: public Ui_admcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMCONTROL_H
