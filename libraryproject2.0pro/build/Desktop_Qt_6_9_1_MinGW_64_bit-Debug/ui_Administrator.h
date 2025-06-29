/********************************************************************************
** Form generated from reading UI file 'Administrator.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Administrator
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label;
    QFrame *frame_3;
    QLineEdit *adaccout;
    QLineEdit *adpassword;
    QPushButton *next;
    QLabel *accout_pic;
    QLabel *password_pic;
    QLabel *Adm_backgroud;

    void setupUi(QDialog *Administrator)
    {
        if (Administrator->objectName().isEmpty())
            Administrator->setObjectName("Administrator");
        Administrator->resize(700, 500);
        Administrator->setMinimumSize(QSize(637, 440));
        Administrator->setMaximumSize(QSize(700, 500));
        QFont font;
        font.setPointSize(15);
        Administrator->setFont(font);
        frame = new QFrame(Administrator);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 50, 591, 389));
        frame->setStyleSheet(QString::fromUtf8("border-radius:10px ;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 40, 280, 300));
        frame_2->setMinimumSize(QSize(280, 300));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"background-color: qlineargradient(spread:pad, x1:0.698864, y1:0.565, x2:1, y2:1, stop:0 rgba(103, 72, 197, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:10px ;}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 240, 80));
        label->setMinimumSize(QSize(240, 80));
        QFont font1;
        font1.setPointSize(9);
        label->setFont(font1);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(290, 40, 280, 301));
        frame_3->setMinimumSize(QSize(280, 280));
        frame_3->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(237, 239, 241);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        adaccout = new QLineEdit(frame_3);
        adaccout->setObjectName("adaccout");
        adaccout->setGeometry(QRect(10, 50, 259, 50));
        adaccout->setMinimumSize(QSize(250, 50));
        QFont font2;
        font2.setPointSize(11);
        adaccout->setFont(font2);
        adaccout->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        adaccout->setClearButtonEnabled(true);
        adpassword = new QLineEdit(frame_3);
        adpassword->setObjectName("adpassword");
        adpassword->setGeometry(QRect(10, 130, 259, 50));
        adpassword->setMinimumSize(QSize(250, 50));
        adpassword->setFont(font2);
        adpassword->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        adpassword->setEchoMode(QLineEdit::EchoMode::Password);
        adpassword->setClearButtonEnabled(true);
        next = new QPushButton(frame_3);
        next->setObjectName("next");
        next->setGeometry(QRect(10, 220, 259, 50));
        next->setMinimumSize(QSize(250, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Modern No. 20")});
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        next->setFont(font3);
        next->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(26, 188, 156);\n"
"\n"
"border-radius:10px ;"));
        next->setAutoDefault(true);
        accout_pic = new QLabel(frame_3);
        accout_pic->setObjectName("accout_pic");
        accout_pic->setGeometry(QRect(220, 60, 21, 31));
        accout_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/zhanghu.png);\n"
"background-color: rgb(255, 255, 255);"));
        password_pic = new QLabel(frame_3);
        password_pic->setObjectName("password_pic");
        password_pic->setGeometry(QRect(220, 140, 21, 31));
        password_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/mima.png);\n"
"background-color: rgb(255, 255, 255);"));
        Adm_backgroud = new QLabel(Administrator);
        Adm_backgroud->setObjectName("Adm_backgroud");
        Adm_backgroud->setGeometry(QRect(0, 0, 700, 500));
        Adm_backgroud->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 73, 94);"));
        Adm_backgroud->raise();
        frame->raise();

        retranslateUi(Administrator);

        QMetaObject::connectSlotsByName(Administrator);
    } // setupUi

    void retranslateUi(QDialog *Administrator)
    {
        Administrator->setWindowTitle(QCoreApplication::translate("Administrator", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Administrator", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#ffffff;\">\346\254\242\350\277\216\347\256\241\347\220\206\345\221\230\347\231\273\345\205\245</span></p></body></html>", nullptr));
        adaccout->setPlaceholderText(QCoreApplication::translate("Administrator", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        adpassword->setPlaceholderText(QCoreApplication::translate("Administrator", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        next->setText(QCoreApplication::translate("Administrator", "\347\231\273\345\275\225", nullptr));
        accout_pic->setText(QString());
        password_pic->setText(QString());
        Adm_backgroud->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Administrator: public Ui_Administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
