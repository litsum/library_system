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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Newreader
{
public:
    QFrame *frame;
    QLabel *accout_pic;
    QLabel *password_pic;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Newreader)
    {
        if (Newreader->objectName().isEmpty())
            Newreader->setObjectName("Newreader");
        Newreader->resize(400, 300);
        Newreader->setMinimumSize(QSize(400, 300));
        Newreader->setMaximumSize(QSize(400, 300));
        frame = new QFrame(Newreader);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 400, 300));
        frame->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(237, 239, 241);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        accout_pic = new QLabel(frame);
        accout_pic->setObjectName("accout_pic");
        accout_pic->setGeometry(QRect(260, 60, 21, 31));
        accout_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/zhanghu.png);\n"
"background-color: rgb(255, 255, 255);"));
        password_pic = new QLabel(frame);
        password_pic->setObjectName("password_pic");
        password_pic->setGeometry(QRect(260, 127, 21, 31));
        password_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/mima.png);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(80, 50, 231, 45));
        QFont font;
        font.setPointSize(12);
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Normal);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 120, 231, 45));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 193, 231, 45));
        pushButton_2->setMinimumSize(QSize(70, 20));
        QFont font1;
        font1.setPointSize(14);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 204, 113);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 271, 231));
        label->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(248, 248, 248);"));
        label->raise();
        lineEdit->raise();
        password_pic->raise();
        lineEdit_2->raise();
        accout_pic->raise();
        pushButton_2->raise();

        retranslateUi(Newreader);

        QMetaObject::connectSlotsByName(Newreader);
    } // setupUi

    void retranslateUi(QDialog *Newreader)
    {
        Newreader->setWindowTitle(QCoreApplication::translate("Newreader", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        accout_pic->setText(QString());
        password_pic->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Newreader", "\346\230\265\347\247\260\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Newreader", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Newreader", "\345\256\214\346\210\220", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Newreader: public Ui_Newreader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWREADER_H
