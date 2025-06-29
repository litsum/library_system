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

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(400, 300);
        frame = new QFrame(registration);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 30, 321, 241));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        accout = new QLineEdit(frame);
        accout->setObjectName("accout");
        accout->setGeometry(QRect(60, 30, 200, 31));
        accout->setMinimumSize(QSize(200, 30));
        accout->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        accout->setEchoMode(QLineEdit::EchoMode::Normal);
        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setGeometry(QRect(60, 100, 200, 31));
        password->setMinimumSize(QSize(200, 30));
        password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 160, 70, 21));
        pushButton->setMinimumSize(QSize(70, 20));
        reg = new QPushButton(frame);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(70, 160, 70, 21));
        reg->setMinimumSize(QSize(70, 20));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Dialog", nullptr));
        accout->setPlaceholderText(QCoreApplication::translate("registration", "\346\230\265\347\247\260\357\274\232", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("registration", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("registration", "\347\231\273\345\275\225", nullptr));
        reg->setText(QCoreApplication::translate("registration", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
