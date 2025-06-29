/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addbook
{
public:
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QLineEdit *author;
    QLineEdit *publisher;
    QLineEdit *ISBN;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *addbook)
    {
        if (addbook->objectName().isEmpty())
            addbook->setObjectName("addbook");
        addbook->resize(609, 370);
        pushButton_4 = new QPushButton(addbook);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(460, 170, 56, 18));
        pushButton_5 = new QPushButton(addbook);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(460, 230, 56, 18));
        verticalLayoutWidget = new QWidget(addbook);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(59, 19, 371, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(verticalLayoutWidget);
        name->setObjectName("name");
        name->setMinimumSize(QSize(250, 30));
        name->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));

        verticalLayout->addWidget(name, 0, Qt::AlignmentFlag::AlignHCenter);

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

        pushButton_3 = new QPushButton(addbook);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 110, 56, 18));
        pushButton_2 = new QPushButton(addbook);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(460, 60, 56, 18));

        retranslateUi(addbook);
        QObject::connect(pushButton_2, &QPushButton::clicked, name, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_3, &QPushButton::clicked, author, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_4, &QPushButton::clicked, publisher, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_5, &QPushButton::clicked, ISBN, qOverload<>(&QLineEdit::clear));

        QMetaObject::connectSlotsByName(addbook);
    } // setupUi

    void retranslateUi(QDialog *addbook)
    {
        addbook->setWindowTitle(QCoreApplication::translate("addbook", "Dialog", nullptr));
        pushButton_4->setText(QCoreApplication::translate("addbook", "\346\270\205\347\251\272", nullptr));
        pushButton_5->setText(QCoreApplication::translate("addbook", "\346\270\205\347\251\272", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("addbook", "\344\271\246\345\220\215\357\274\232", nullptr));
        author->setPlaceholderText(QCoreApplication::translate("addbook", "\344\275\234\350\200\205\357\274\232", nullptr));
        publisher->setPlaceholderText(QCoreApplication::translate("addbook", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        ISBN->setPlaceholderText(QCoreApplication::translate("addbook", "ISBN\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("addbook", "\347\241\256\350\256\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("addbook", "\346\270\205\347\251\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("addbook", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addbook: public Ui_addbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
