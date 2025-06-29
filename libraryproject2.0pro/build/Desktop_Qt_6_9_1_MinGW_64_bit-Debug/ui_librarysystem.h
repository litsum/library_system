/********************************************************************************
** Form generated from reading UI file 'librarysystem.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYSYSTEM_H
#define UI_LIBRARYSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibrarySystem
{
public:
    QLabel *label;
    QPushButton *close;
    QPushButton *ad;
    QPushButton *re;
    QLabel *backgroud_1;
    QLabel *backgroud_2;

    void setupUi(QWidget *LibrarySystem)
    {
        if (LibrarySystem->objectName().isEmpty())
            LibrarySystem->setObjectName("LibrarySystem");
        LibrarySystem->resize(600, 400);
        LibrarySystem->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(LibrarySystem);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 50, 281, 61));
        label->setStyleSheet(QString::fromUtf8(""));
        close = new QPushButton(LibrarySystem);
        close->setObjectName("close");
        close->setGeometry(QRect(50, 330, 81, 31));
        QFont font;
        font.setPointSize(14);
        close->setFont(font);
        close->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 194, 58);\n"
"border-radius:30px ;"));
        ad = new QPushButton(LibrarySystem);
        ad->setObjectName("ad");
        ad->setGeometry(QRect(170, 150, 250, 51));
        ad->setMinimumSize(QSize(250, 45));
        QFont font1;
        font1.setPointSize(18);
        ad->setFont(font1);
        ad->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 158, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px ;"));
        ad->setIconSize(QSize(200, 100));
        re = new QPushButton(LibrarySystem);
        re->setObjectName("re");
        re->setGeometry(QRect(170, 230, 250, 51));
        re->setMinimumSize(QSize(250, 45));
        re->setFont(font1);
        re->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 158, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px ;"));
        backgroud_1 = new QLabel(LibrarySystem);
        backgroud_1->setObjectName("backgroud_1");
        backgroud_1->setGeometry(QRect(30, 20, 531, 361));
        backgroud_1->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 188, 156);\n"
"border-radius:20px ;"));
        backgroud_2 = new QLabel(LibrarySystem);
        backgroud_2->setObjectName("backgroud_2");
        backgroud_2->setGeometry(QRect(0, 0, 600, 400));
        backgroud_2->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 73, 94);"));
        backgroud_2->raise();
        backgroud_1->raise();
        close->raise();
        label->raise();
        ad->raise();
        re->raise();

        retranslateUi(LibrarySystem);

        QMetaObject::connectSlotsByName(LibrarySystem);
    } // setupUi

    void retranslateUi(QWidget *LibrarySystem)
    {
        LibrarySystem->setWindowTitle(QCoreApplication::translate("LibrarySystem", "\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("LibrarySystem", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700; color:#ffffff;\">\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        close->setText(QCoreApplication::translate("LibrarySystem", "\344\277\235\345\255\230", nullptr));
        ad->setText(QCoreApplication::translate("LibrarySystem", "\347\256\241\347\220\206\345\221\230\347\231\273\345\205\245", nullptr));
        re->setText(QCoreApplication::translate("LibrarySystem", "\350\257\273\350\200\205\347\231\273\345\205\245", nullptr));
        backgroud_1->setText(QString());
        backgroud_2->setText(QCoreApplication::translate("LibrarySystem", "\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarySystem: public Ui_LibrarySystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYSYSTEM_H
