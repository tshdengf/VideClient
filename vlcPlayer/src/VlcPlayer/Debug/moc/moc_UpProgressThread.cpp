/****************************************************************************
** Meta object code from reading C++ file 'UpProgressThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UpProgressThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpProgressThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileProgressThread_t {
    QByteArrayData data[10];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileProgressThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileProgressThread_t qt_meta_stringdata_FileProgressThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FileProgressThread"
QT_MOC_LITERAL(1, 19, 14), // "updateProgress"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "num"
QT_MOC_LITERAL(4, 39, 11), // "progressMsg"
QT_MOC_LITERAL(5, 51, 5), // "error"
QT_MOC_LITERAL(6, 57, 3), // "msg"
QT_MOC_LITERAL(7, 61, 11), // "StopOrStart"
QT_MOC_LITERAL(8, 73, 6), // "Resume"
QT_MOC_LITERAL(9, 80, 5) // "Pause"

    },
    "FileProgressThread\0updateProgress\0\0"
    "num\0progressMsg\0error\0msg\0StopOrStart\0"
    "Resume\0Pause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileProgressThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x0a /* Public */,
       8,    0,   48,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileProgressThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileProgressThread *_t = static_cast<FileProgressThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->progressMsg((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->StopOrStart(); break;
        case 3: _t->Resume(); break;
        case 4: _t->Pause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileProgressThread::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileProgressThread::updateProgress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileProgressThread::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileProgressThread::progressMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FileProgressThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FileProgressThread.data,
      qt_meta_data_FileProgressThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileProgressThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileProgressThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileProgressThread.stringdata0))
        return static_cast<void*>(const_cast< FileProgressThread*>(this));
    return QThread::qt_metacast(_clname);
}

int FileProgressThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FileProgressThread::updateProgress(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileProgressThread::progressMsg(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
