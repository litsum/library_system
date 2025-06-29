/********************************************************************************
** Form generated from reading UI file 'delete_.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE__H
#define UI_DELETE__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_delete_
{
public:
    QLineEdit *name;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *delete_)
    {
        if (delete_->objectName().isEmpty())
            delete_->setObjectName("delete_");
        delete_->resize(400, 300);
        name = new QLineEdit(delete_);
        name->setObjectName("name");
        name->setGeometry(QRect(40, 120, 250, 30));
        name->setMinimumSize(QSize(250, 30));
        name->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"	border-bottom:1px solid black;}"));
        pushButton = new QPushButton(delete_);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 130, 56, 18));
        pushButton_2 = new QPushButton(delete_);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 210, 151, 30));
        pushButton_2->setMinimumSize(QSize(150, 30));

        retranslateUi(delete_);
        QObject::connect(pushButton, &QPushButton::clicked, name, qOverload<>(&QLineEdit::clear));

        QMetaObject::connectSlotsByName(delete_);
    } // setupUi

    void retranslateUi(QDialog *delete_)
    {
        delete_->setWindowTitle(QCoreApplication::translate("delete_", "Dialog", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("delete_", "\344\271\246\345\220\215\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("delete_", "\346\270\205\347\251\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("delete_", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_: public Ui_delete_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE__H
