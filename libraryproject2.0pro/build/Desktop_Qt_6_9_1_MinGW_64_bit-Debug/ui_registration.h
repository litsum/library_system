/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QFrame *frame;
    QLineEdit *accout;
    QLineEdit *password;
    QPushButton *pushButton;
    QPushButton *reg;
    QLabel *accout_pic;
    QLabel *password_pic;
    QLabel *Adm_backgroud;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(700, 500);
        frame = new QFrame(registration);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(280, 130, 351, 241));
        frame->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"background-color: rgb(237, 239, 241);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        accout = new QLineEdit(frame);
        accout->setObjectName("accout");
        accout->setGeometry(QRect(60, 40, 240, 45));
        accout->setMinimumSize(QSize(200, 30));
        QFont font;
        font.setPointSize(11);
        accout->setFont(font);
        accout->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        accout->setEchoMode(QLineEdit::EchoMode::Normal);
        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setGeometry(QRect(60, 100, 240, 45));
        password->setMinimumSize(QSize(200, 30));
        password->setFont(font);
        password->setStyleSheet(QString::fromUtf8("border-radius:10px ;\n"
"color: rgb(183, 183, 183);\n"
"background-color: rgb(255, 255, 255);"));
        password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(196, 160, 105, 45));
        pushButton->setMinimumSize(QSize(70, 20));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 188, 156);\n"
"color: rgb(255, 255, 255);"));
        reg = new QPushButton(frame);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(60, 160, 105, 45));
        reg->setMinimumSize(QSize(70, 20));
        reg->setFont(font);
        reg->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 204, 113);\n"
"color: rgb(255, 255, 255);"));
        accout_pic = new QLabel(frame);
        accout_pic->setObjectName("accout_pic");
        accout_pic->setGeometry(QRect(254, 45, 21, 31));
        accout_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/zhanghu.png);\n"
"background-color: rgb(255, 255, 255);"));
        password_pic = new QLabel(frame);
        password_pic->setObjectName("password_pic");
        password_pic->setGeometry(QRect(254, 106, 21, 31));
        password_pic->setStyleSheet(QString::fromUtf8("background-image: url(:/mima.png);\n"
"background-color: rgb(255, 255, 255);"));
        Adm_backgroud = new QLabel(registration);
        Adm_backgroud->setObjectName("Adm_backgroud");
        Adm_backgroud->setGeometry(QRect(0, 0, 700, 500));
        Adm_backgroud->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 73, 94);"));
        label = new QLabel(registration);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 140, 191, 141));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/reg_1.png);\n"
"\n"
"border-radius:10px ;"));
        label_2 = new QLabel(registration);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 298, 191, 61));
        QFont font1;
        font1.setPointSize(17);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Adm_backgroud->raise();
        frame->raise();
        label->raise();
        label_2->raise();

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "\350\257\273\350\200\205\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        accout->setPlaceholderText(QCoreApplication::translate("registration", "\346\230\265\347\247\260\357\274\232", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("registration", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("registration", "\347\231\273\345\275\225", nullptr));
        reg->setText(QCoreApplication::translate("registration", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        accout_pic->setText(QString());
        password_pic->setText(QString());
        Adm_backgroud->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("registration", "\346\254\242\350\277\216\350\257\273\350\200\205\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
