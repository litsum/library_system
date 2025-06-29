/********************************************************************************
** Form generated from reading UI file 'Newreader.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWREADER_H
#define UI_NEWREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Newreader
{
public:
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Newreader)
    {
        if (Newreader->objectName().isEmpty())
            Newreader->setObjectName("Newreader");
        Newreader->resize(400, 300);
        pushButton_2 = new QPushButton(Newreader);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 210, 70, 20));
        pushButton_2->setMinimumSize(QSize(70, 20));
        lineEdit = new QLineEdit(Newreader);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(112, 140, 161, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_2 = new QLineEdit(Newreader);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 80, 161, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Normal);

        retranslateUi(Newreader);

        QMetaObject::connectSlotsByName(Newreader);
    } // setupUi

    void retranslateUi(QDialog *Newreader)
    {
        Newreader->setWindowTitle(QCoreApplication::translate("Newreader", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Newreader", "\345\256\214\346\210\220", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Newreader", "\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Newreader", "\346\230\265\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Newreader: public Ui_Newreader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWREADER_H
