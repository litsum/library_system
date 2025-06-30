/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName("add");
        add->resize(400, 300);
        add->setMinimumSize(QSize(400, 300));
        add->setMaximumSize(QSize(400, 300));
        pushButton = new QPushButton(add);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 150, 91, 31));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 204, 113);\n"
"border-radius:10px ;"));
        pushButton_2 = new QPushButton(add);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 150, 91, 31));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(189, 195, 199);"));
        label = new QLabel(add);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 80, 281, 51));
        label_2 = new QLabel(add);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 50, 271, 171));
        label_2->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(248, 248, 248);"));
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        label->raise();

        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QDialog *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("add", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("add", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("add", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">\346\202\250\347\241\256\350\256\244\345\200\237\351\230\205\346\255\244\344\271\246\345\220\227\357\274\237</span></p></body></html>", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
