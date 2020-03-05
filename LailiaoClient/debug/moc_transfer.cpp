/****************************************************************************
** Meta object code from reading C++ file 'transfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Transfer_t {
    QByteArrayData data[10];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Transfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Transfer_t qt_meta_stringdata_Transfer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Transfer"
QT_MOC_LITERAL(1, 9, 12), // "sendFileName"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "fileName"
QT_MOC_LITERAL(4, 32, 11), // "sendMessage"
QT_MOC_LITERAL(5, 44, 20), // "updateClientProgress"
QT_MOC_LITERAL(6, 65, 8), // "numBytes"
QT_MOC_LITERAL(7, 74, 28), // "on_toolButton_select_clicked"
QT_MOC_LITERAL(8, 103, 18), // "on_sendBtn_clicked"
QT_MOC_LITERAL(9, 122, 18) // "on_quitBtn_clicked"

    },
    "Transfer\0sendFileName\0\0fileName\0"
    "sendMessage\0updateClientProgress\0"
    "numBytes\0on_toolButton_select_clicked\0"
    "on_sendBtn_clicked\0on_quitBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transfer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Transfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Transfer *_t = static_cast<Transfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendMessage(); break;
        case 2: _t->updateClientProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->on_toolButton_select_clicked(); break;
        case 4: _t->on_sendBtn_clicked(); break;
        case 5: _t->on_quitBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Transfer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Transfer::sendFileName)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Transfer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Transfer.data,
      qt_meta_data_Transfer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Transfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transfer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Transfer.stringdata0))
        return static_cast<void*>(const_cast< Transfer*>(this));
    return QWidget::qt_metacast(_clname);
}

int Transfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Transfer::sendFileName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
