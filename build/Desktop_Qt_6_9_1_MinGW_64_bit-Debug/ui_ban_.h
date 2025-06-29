/********************************************************************************
** Form generated from reading UI file 'ban_.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAN__H
#define UI_BAN__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ban_
{
public:
    QLineEdit *readername;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *readername_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ban_)
    {
        if (ban_->objectName().isEmpty())
            ban_->setObjectName("ban_");
        ban_->resize(400, 300);
        readername = new QLineEdit(ban_);
        readername->setObjectName("readername");
        readername->setGeometry(QRect(50, 140, 250, 30));
        readername->setMinimumSize(QSize(250, 30));
        readername->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton = new QPushButton(ban_);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 150, 56, 18));
        pushButton_2 = new QPushButton(ban_);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 220, 56, 18));
        readername_2 = new QLineEdit(ban_);
        readername_2->setObjectName("readername_2");
        readername_2->setGeometry(QRect(50, 70, 250, 30));
        readername_2->setMinimumSize(QSize(250, 30));
        readername_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton_3 = new QPushButton(ban_);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(320, 80, 56, 18));

        retranslateUi(ban_);
        QObject::connect(pushButton, &QPushButton::clicked, readername, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_3, &QPushButton::clicked, readername_2, qOverload<>(&QLineEdit::clear));

        QMetaObject::connectSlotsByName(ban_);
    } // setupUi

    void retranslateUi(QDialog *ban_)
    {
        ban_->setWindowTitle(QCoreApplication::translate("ban_", "Dialog", nullptr));
        readername->setPlaceholderText(QCoreApplication::translate("ban_", "\345\260\201\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("ban_", "\346\270\205\347\251\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ban_", "\347\241\256\350\256\244", nullptr));
        readername_2->setPlaceholderText(QCoreApplication::translate("ban_", "\350\247\243\347\246\201\350\257\273\350\200\205\345\220\215\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ban_", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ban_: public Ui_ban_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAN__H
