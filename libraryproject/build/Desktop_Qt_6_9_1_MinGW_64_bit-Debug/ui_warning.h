/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_warning
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QDialog *warning)
    {
        if (warning->objectName().isEmpty())
            warning->setObjectName("warning");
        warning->resize(400, 300);
        label = new QLabel(warning);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 381, 141));
        pushButton = new QPushButton(warning);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 170, 100, 40));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 204, 113);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px ;"));
        pushButton_2 = new QPushButton(warning);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 170, 100, 40));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 195, 199);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px ;"));
        label_2 = new QLabel(warning);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 400, 300));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(248, 248, 248);"));
        label_2->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(warning);

        QMetaObject::connectSlotsByName(warning);
    } // setupUi

    void retranslateUi(QDialog *warning)
    {
        warning->setWindowTitle(QCoreApplication::translate("warning", "\350\255\246\345\221\212\357\274\201", nullptr));
        label->setText(QCoreApplication::translate("warning", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\346\202\250\350\277\230\346\234\252\344\277\235\345\255\230\357\274\214\346\230\257\345\220\246\350\246\201\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272\357\274\232</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("warning", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("warning", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class warning: public Ui_warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
