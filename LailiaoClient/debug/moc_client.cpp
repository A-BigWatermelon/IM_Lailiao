/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[22];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 6), // "toQuit"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 17), // "newConnectionSlot"
QT_MOC_LITERAL(4, 33, 14), // "sendOnlineSlot"
QT_MOC_LITERAL(5, 48, 15), // "sendOffLineSlot"
QT_MOC_LITERAL(6, 64, 24), // "checkConnectionStateSLot"
QT_MOC_LITERAL(7, 89, 22), // "timerToCheckConnection"
QT_MOC_LITERAL(8, 112, 14), // "searchFormSlot"
QT_MOC_LITERAL(9, 127, 12), // "showChatForm"
QT_MOC_LITERAL(10, 140, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(11, 157, 18), // "readTCPMessageSlot"
QT_MOC_LITERAL(12, 176, 15), // "readMessageSlot"
QT_MOC_LITERAL(13, 192, 18), // "addNewFriendToList"
QT_MOC_LITERAL(14, 211, 10), // "outputlist"
QT_MOC_LITERAL(15, 222, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(16, 254, 5), // "index"
QT_MOC_LITERAL(17, 260, 40), // "on_treeWidget_customContextMe..."
QT_MOC_LITERAL(18, 301, 3), // "pos"
QT_MOC_LITERAL(19, 305, 25), // "on_actionDelete_activated"
QT_MOC_LITERAL(20, 331, 4), // "arg1"
QT_MOC_LITERAL(21, 336, 22) // "on_actionAdd_activated"

    },
    "Client\0toQuit\0\0newConnectionSlot\0"
    "sendOnlineSlot\0sendOffLineSlot\0"
    "checkConnectionStateSLot\0"
    "timerToCheckConnection\0searchFormSlot\0"
    "showChatForm\0QTreeWidgetItem*\0"
    "readTCPMessageSlot\0readMessageSlot\0"
    "addNewFriendToList\0outputlist\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_treeWidget_customContextMenuRequested\0"
    "pos\0on_actionDelete_activated\0arg1\0"
    "on_actionAdd_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

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
       1,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    2,  101,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    3,  108,    2, 0x08 /* Private */,
      14,    1,  115,    2, 0x08 /* Private */,
      15,    1,  118,    2, 0x08 /* Private */,
      17,    1,  121,    2, 0x08 /* Private */,
      19,    1,  124,    2, 0x08 /* Private */,
      21,    0,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QPoint,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toQuit(); break;
        case 1: _t->newConnectionSlot(); break;
        case 2: _t->sendOnlineSlot(); break;
        case 3: _t->sendOffLineSlot(); break;
        case 4: _t->checkConnectionStateSLot(); break;
        case 5: _t->timerToCheckConnection(); break;
        case 6: _t->searchFormSlot(); break;
        case 7: _t->showChatForm((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->readTCPMessageSlot(); break;
        case 9: _t->readMessageSlot(); break;
        case 10: _t->addNewFriendToList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->outputlist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_treeWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->on_actionDelete_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_actionAdd_activated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::toQuit)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Client::toQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
