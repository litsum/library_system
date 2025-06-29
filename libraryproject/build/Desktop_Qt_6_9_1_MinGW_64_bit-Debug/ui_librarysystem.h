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

    void setupUi(QWidget *LibrarySystem)
    {
        if (LibrarySystem->objectName().isEmpty())
            LibrarySystem->setObjectName("LibrarySystem");
        LibrarySystem->resize(460, 311);
        label = new QLabel(LibrarySystem);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 10, 201, 41));
        close = new QPushButton(LibrarySystem);
        close->setObjectName("close");
        close->setGeometry(QRect(10, 290, 56, 18));
        ad = new QPushButton(LibrarySystem);
        ad->setObjectName("ad");
        ad->setGeometry(QRect(100, 80, 250, 50));
        ad->setMinimumSize(QSize(250, 50));
        ad->setIconSize(QSize(200, 100));
        re = new QPushButton(LibrarySystem);
        re->setObjectName("re");
        re->setGeometry(QRect(100, 160, 250, 50));
        re->setMinimumSize(QSize(250, 50));

        retranslateUi(LibrarySystem);

        QMetaObject::connectSlotsByName(LibrarySystem);
    } // setupUi

    void retranslateUi(QWidget *LibrarySystem)
    {
        LibrarySystem->setWindowTitle(QCoreApplication::translate("LibrarySystem", "Widget", nullptr));
        label->setText(QCoreApplication::translate("LibrarySystem", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#0055ff;\">\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        close->setText(QCoreApplication::translate("LibrarySystem", "\344\277\235\345\255\230", nullptr));
        ad->setText(QCoreApplication::translate("LibrarySystem", "\347\256\241\347\220\206\345\221\230\347\231\273\345\205\245", nullptr));
        re->setText(QCoreApplication::translate("LibrarySystem", "\350\257\273\350\200\205\347\231\273\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarySystem: public Ui_LibrarySystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYSYSTEM_H
