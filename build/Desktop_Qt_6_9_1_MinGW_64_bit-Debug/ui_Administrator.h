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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Administrator
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label;
    QFrame *frame_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *adaccout;
    QLineEdit *adpassword;
    QPushButton *next;

    void setupUi(QDialog *Administrator)
    {
        if (Administrator->objectName().isEmpty())
            Administrator->setObjectName("Administrator");
        Administrator->resize(799, 509);
        Administrator->setMinimumSize(QSize(637, 440));
        frame = new QFrame(Administrator);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 0, 609, 389));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 20, 280, 300));
        frame_2->setMinimumSize(QSize(280, 300));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"background-color: qlineargradient(spread:pad, x1:0.698864, y1:0.565, x2:1, y2:1, stop:0 rgba(103, 72, 197, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius:20px ;}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 240, 80));
        label->setMinimumSize(QSize(240, 80));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(290, 40, 280, 281));
        frame_3->setMinimumSize(QSize(280, 280));
        frame_3->setStyleSheet(QString::fromUtf8(""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget_2 = new QWidget(frame_3);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(9, 9, 252, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        adaccout = new QLineEdit(verticalLayoutWidget_2);
        adaccout->setObjectName("adaccout");
        adaccout->setMinimumSize(QSize(250, 50));
        adaccout->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        adaccout->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(adaccout);

        adpassword = new QLineEdit(verticalLayoutWidget_2);
        adpassword->setObjectName("adpassword");
        adpassword->setMinimumSize(QSize(250, 50));
        adpassword->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        adpassword->setEchoMode(QLineEdit::EchoMode::Password);
        adpassword->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(adpassword);

        next = new QPushButton(verticalLayoutWidget_2);
        next->setObjectName("next");
        next->setMinimumSize(QSize(250, 50));
        next->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 9pt \"Modern No. 20\";"));

        verticalLayout_2->addWidget(next);


        retranslateUi(Administrator);

        QMetaObject::connectSlotsByName(Administrator);
    } // setupUi

    void retranslateUi(QDialog *Administrator)
    {
        Administrator->setWindowTitle(QCoreApplication::translate("Administrator", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Administrator", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">\346\254\242\350\277\216\347\256\241\347\220\206\345\221\230\347\231\273\345\205\245</span></p></body></html>", nullptr));
        adaccout->setPlaceholderText(QCoreApplication::translate("Administrator", "\350\264\246\345\217\267\357\274\232", nullptr));
        adpassword->setPlaceholderText(QCoreApplication::translate("Administrator", "\345\257\206\347\240\201\357\274\232", nullptr));
        next->setText(QCoreApplication::translate("Administrator", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Administrator: public Ui_Administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
