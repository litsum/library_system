QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QMAKE_CXXFLAGS += -finput-charset=UTF-8
QMAKE_CXXFLAGS += -fexec-charset=UTF-8
SOURCES += \
    Administrator.cpp \
    Newreader.cpp \
    admcontrol.cpp \
    database.cpp \
    find.cpp \
    librarydatabase.cpp \
    librarysystem.cpp \
    main.cpp \
    readercol.cpp \
    registration.cpp \
    warning.cpp

HEADERS += \
    Administrator.h \
    Newreader.h \
    Reader.h \
    admcontrol.h \
    book.h \
    database.h \
    find.h \
    librarydatabase.h \
    librarysystem.h \
    readercol.h \
    registration.h \
    warning.h

FORMS += \
    Administrator.ui \
    Newreader.ui \
    admcontrol.ui \
    librarysystem.ui \
    readercol.ui \
    registration.ui \
    warning.ui

TRANSLATIONS += \
    libraryproject_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES += \
    book1.txt \
    book2.txt \
    readers.txt
