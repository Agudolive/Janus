/****************************************************************************
** Meta object code from reading C++ file 'fenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Janus/fenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Fenetre_t {
    QByteArrayData data[13];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fenetre_t qt_meta_stringdata_Fenetre = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Fenetre"
QT_MOC_LITERAL(1, 8, 21), // "slot_selectionChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "QItemSelection"
QT_MOC_LITERAL(4, 46, 8), // "selected"
QT_MOC_LITERAL(5, 55, 10), // "deselected"
QT_MOC_LITERAL(6, 66, 16), // "slot_textchanged"
QT_MOC_LITERAL(7, 83, 6), // "string"
QT_MOC_LITERAL(8, 90, 16), // "slot_ecriturebtn"
QT_MOC_LITERAL(9, 107, 14), // "slot_tabwidget"
QT_MOC_LITERAL(10, 122, 5), // "index"
QT_MOC_LITERAL(11, 128, 19), // "slot_button_valider"
QT_MOC_LITERAL(12, 148, 16) // "slot_button_read"

    },
    "Fenetre\0slot_selectionChanged\0\0"
    "QItemSelection\0selected\0deselected\0"
    "slot_textchanged\0string\0slot_ecriturebtn\0"
    "slot_tabwidget\0index\0slot_button_valider\0"
    "slot_button_read"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fenetre[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,
      11,    0,   56,    2, 0x0a /* Public */,
      12,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Fenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fenetre *_t = static_cast<Fenetre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->slot_textchanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slot_ecriturebtn(); break;
        case 3: _t->slot_tabwidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_button_valider(); break;
        case 5: _t->slot_button_read(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject Fenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fenetre.data,
      qt_meta_data_Fenetre,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Fenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre.stringdata0))
        return static_cast<void*>(const_cast< Fenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int Fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
