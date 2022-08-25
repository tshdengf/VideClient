/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWidget_t {
    QByteArrayData data[20];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWidget_t qt_meta_stringdata_MainWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWidget"
QT_MOC_LITERAL(1, 11, 5), // "Close"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "ShowPlay"
QT_MOC_LITERAL(4, 27, 5), // "index"
QT_MOC_LITERAL(5, 33, 10), // "updateTime"
QT_MOC_LITERAL(6, 44, 9), // "RateClick"
QT_MOC_LITERAL(7, 54, 11), // "SliderClick"
QT_MOC_LITERAL(8, 66, 5), // "value"
QT_MOC_LITERAL(9, 72, 11), // "UPFileClick"
QT_MOC_LITERAL(10, 84, 10), // "StopUpLoad"
QT_MOC_LITERAL(11, 95, 9), // "CutUpLoad"
QT_MOC_LITERAL(12, 105, 22), // "processVideoFileUpdate"
QT_MOC_LITERAL(13, 128, 29), // "QList<QMap<QString,QString> >"
QT_MOC_LITERAL(14, 158, 3), // "res"
QT_MOC_LITERAL(15, 162, 19), // "updateFileUpLoadPro"
QT_MOC_LITERAL(16, 182, 3), // "num"
QT_MOC_LITERAL(17, 186, 21), // "progressFileUpLoadMsg"
QT_MOC_LITERAL(18, 208, 5), // "error"
QT_MOC_LITERAL(19, 214, 3) // "msg"

    },
    "MainWidget\0Close\0\0ShowPlay\0index\0"
    "updateTime\0RateClick\0SliderClick\0value\0"
    "UPFileClick\0StopUpLoad\0CutUpLoad\0"
    "processVideoFileUpdate\0"
    "QList<QMap<QString,QString> >\0res\0"
    "updateFileUpLoadPro\0num\0progressFileUpLoadMsg\0"
    "error\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    1,   70,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    0,   74,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
       9,    0,   78,    2, 0x0a /* Public */,
      10,    0,   79,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      15,    1,   84,    2, 0x0a /* Public */,
      17,    2,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   18,   19,

       0        // eod
};

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWidget *_t = static_cast<MainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Close(); break;
        case 1: _t->ShowPlay((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->updateTime(); break;
        case 3: _t->RateClick(); break;
        case 4: _t->SliderClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->UPFileClick(); break;
        case 6: _t->StopUpLoad(); break;
        case 7: _t->CutUpLoad(); break;
        case 8: _t->processVideoFileUpdate((*reinterpret_cast< QList<QMap<QString,QString> >(*)>(_a[1]))); break;
        case 9: _t->updateFileUpLoadPro((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->progressFileUpLoadMsg((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWidget.data,
      qt_meta_data_MainWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget.stringdata0))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
