/****************************************************************************
** Meta object code from reading C++ file 'delete_.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../delete_.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delete_.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7delete_E_t {};
} // unnamed namespace

template <> constexpr inline auto delete_::qt_create_metaobjectdata<qt_meta_tag_ZN7delete_E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "delete_",
        "bookdelete1",
        "",
        "std::vector<Book1>::iterator",
        "it",
        "bookdelete2",
        "std::vector<Book2>::iterator",
        "on_pushButton_2_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'bookdelete1'
        QtMocHelpers::SignalData<void(const std::vector<Book1>::iterator)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'bookdelete2'
        QtMocHelpers::SignalData<void(const std::vector<Book2>::iterator)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 4 },
        }}),
        // Slot 'on_pushButton_2_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<delete_, qt_meta_tag_ZN7delete_E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject delete_::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7delete_E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7delete_E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7delete_E_t>.metaTypes,
    nullptr
} };

void delete_::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<delete_ *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->bookdelete1((*reinterpret_cast< std::add_pointer_t<std::vector<Book1>::iterator>>(_a[1]))); break;
        case 1: _t->bookdelete2((*reinterpret_cast< std::add_pointer_t<std::vector<Book2>::iterator>>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (delete_::*)(const std::vector<Book1>::iterator )>(_a, &delete_::bookdelete1, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (delete_::*)(const std::vector<Book2>::iterator )>(_a, &delete_::bookdelete2, 1))
            return;
    }
}

const QMetaObject *delete_::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *delete_::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7delete_E_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int delete_::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void delete_::bookdelete1(const std::vector<Book1>::iterator _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void delete_::bookdelete2(const std::vector<Book2>::iterator _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
