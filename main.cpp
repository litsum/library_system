#include "librarysystem.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <ostream>
#include <istream>
#include <iostream>
#include "database.h"
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db;
    qDebug() << "Using QODBC driver";
    db = QSqlDatabase::addDatabase("QODBC");
    QString dsn = "DRIVER={MySQL ODBC 9.3 Unicode Driver};"
                  "SERVER=117.72.62.143;"
                  "PORT=3306;"
                  "DATABASE=librarydatabase;"
                  "USER=remote_user;"
                  "PASSWORD=6$n[zp|0I5B@mAn;";
    db.setDatabaseName(dsn);
    if (!db.open()) {
        QSqlError error = db.lastError();
        qDebug() << "Connect error:" << error.text();

        QMessageBox::critical(nullptr, "Database Error",
                              QString("Failed to connect to database:\n\n"
                                      "Driver: %1\n"
                                      "Error code: %2\n"
                                      "Error message: %3")
                                  .arg(db.driverName())
                                  .arg(error.nativeErrorCode())
                                  .arg(error.text()));
        return -1;
    }
    qDebug() << "Database connected successfully";
    // 设置数据库连接给单例
    LibraryDatabase::getInstance().setDatabase(db);

    // 加载数据
    if (!LibraryDatabase::getInstance().loadData()) {
        QMessageBox::critical(nullptr, "Load Error",
                              "Failed to load data from database");
        return -1;
    }
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "libraryproject_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Widget w;
    w.show();
    return a.exec();
}
