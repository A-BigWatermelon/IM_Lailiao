/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Chat_t {
    QByteArrayData data[24];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 11), // "closebutton"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "sendMessageSlot"
QT_MOC_LITERAL(4, 34, 18), // "receiveMessageSlot"
QT_MOC_LITERAL(5, 53, 9), // "setFontxx"
QT_MOC_LITERAL(6, 63, 12), // "setFontColor"
QT_MOC_LITERAL(7, 76, 12), // "showfaceSlot"
QT_MOC_LITERAL(8, 89, 20), // "currentFormatChanged"
QT_MOC_LITERAL(9, 110, 15), // "QTextCharFormat"
QT_MOC_LITERAL(10, 126, 12), // "sentFileName"
QT_MOC_LITERAL(11, 139, 14), // "hasPendingFile"
QT_MOC_LITERAL(12, 154, 8), // "userName"
QT_MOC_LITERAL(13, 163, 13), // "serverAddress"
QT_MOC_LITERAL(14, 177, 13), // "clientAddress"
QT_MOC_LITERAL(15, 191, 8), // "fileName"
QT_MOC_LITERAL(16, 200, 26), // "on_toolButton_Bold_clicked"
QT_MOC_LITERAL(17, 227, 7), // "checked"
QT_MOC_LITERAL(18, 235, 28), // "on_toolButton_Italic_clicked"
QT_MOC_LITERAL(19, 264, 31), // "on_toolButton_Underline_clicked"
QT_MOC_LITERAL(20, 296, 30), // "on_toolButton_SendFile_clicked"
QT_MOC_LITERAL(21, 327, 32), // "on_toolButton_ScreenShot_clicked"
QT_MOC_LITERAL(22, 360, 26), // "on_toolButton_Save_clicked"
QT_MOC_LITERAL(23, 387, 27) // "on_toolButton_Nudge_clicked"

    },
    "Chat\0closebutton\0\0sendMessageSlot\0"
    "receiveMessageSlot\0setFontxx\0setFontColor\0"
    "showfaceSlot\0currentFormatChanged\0"
    "QTextCharFormat\0sentFileName\0"
    "hasPendingFile\0userName\0serverAddress\0"
    "clientAddress\0fileName\0"
    "on_toolButton_Bold_clicked\0checked\0"
    "on_toolButton_Italic_clicked\0"
    "on_toolButton_Underline_clicked\0"
    "on_toolButton_SendFile_clicked\0"
    "on_toolButton_ScreenShot_clicked\0"
    "on_toolButton_Save_clicked\0"
    "on_toolButton_Nudge_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   97,    2, 0x08 /* Private */,
       4,    0,   98,    2, 0x08 /* Private */,
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    1,  101,    2, 0x08 /* Private */,
       8,    1,  104,    2, 0x08 /* Private */,
      10,    1,  107,    2, 0x08 /* Private */,
      11,    4,  110,    2, 0x08 /* Private */,
      16,    1,  119,    2, 0x08 /* Private */,
      18,    1,  122,    2, 0x08 /* Private */,
      19,    1,  125,    2, 0x08 /* Private */,
      20,    0,  128,    2, 0x08 /* Private */,
      21,    0,  129,    2, 0x08 /* Private */,
      22,    0,  130,    2, 0x08 /* Private */,
      23,    0,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chat *_t = static_cast<Chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closebutton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendMessageSlot(); break;
        case 2: _t->receiveMessageSlot(); break;
        case 3: _t->setFontxx(); break;
        case 4: _t->setFontColor(); break;
        case 5: _t->showfaceSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 7: _t->sentFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->hasPendingFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->on_toolButton_Bold_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_toolButton_Italic_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_toolButton_Underline_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_toolButton_SendFile_clicked(); break;
        case 13: _t->on_toolButton_ScreenShot_clicked(); break;
        case 14: _t->on_toolButton_Save_clicked(); break;
        case 15: _t->on_toolButton_Nudge_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Chat::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chat::closebutton)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Chat::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Chat.data,
      qt_meta_data_Chat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(const_cast< Chat*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Chat::closebutton(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
