/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 15. Jun 14:42:40 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProjetLO21/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,
     317,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     344,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     371,   11,   11,   11, 0x08,
     386,   11,   11,   11, 0x08,
     396,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0num0Pressed()\0num1Pressed()\0"
    "num2Pressed()\0num3Pressed()\0num4Pressed()\0"
    "num5Pressed()\0num6Pressed()\0num7Pressed()\0"
    "num8Pressed()\0num9Pressed()\0"
    "numPOINTPressed()\0numQUOTEPressed()\0"
    "numSPACEPressed()\0typeChanged()\0"
    "numPLUSPressed()\0numMINUSPressed()\0"
    "numMULTPressed()\0numDIVPressed()\0"
    "enterPressed()\0evalPressed()\0dropPressed()\0"
    "dupPressed()\0sumPressed()\0swapPressed()\0"
    "clearPressed()\0annuler()\0retablir()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->num0Pressed(); break;
        case 1: _t->num1Pressed(); break;
        case 2: _t->num2Pressed(); break;
        case 3: _t->num3Pressed(); break;
        case 4: _t->num4Pressed(); break;
        case 5: _t->num5Pressed(); break;
        case 6: _t->num6Pressed(); break;
        case 7: _t->num7Pressed(); break;
        case 8: _t->num8Pressed(); break;
        case 9: _t->num9Pressed(); break;
        case 10: _t->numPOINTPressed(); break;
        case 11: _t->numQUOTEPressed(); break;
        case 12: _t->numSPACEPressed(); break;
        case 13: _t->typeChanged(); break;
        case 14: _t->numPLUSPressed(); break;
        case 15: _t->numMINUSPressed(); break;
        case 16: _t->numMULTPressed(); break;
        case 17: _t->numDIVPressed(); break;
        case 18: _t->enterPressed(); break;
        case 19: _t->evalPressed(); break;
        case 20: _t->dropPressed(); break;
        case 21: _t->dupPressed(); break;
        case 22: _t->sumPressed(); break;
        case 23: _t->swapPressed(); break;
        case 24: _t->clearPressed(); break;
        case 25: _t->annuler(); break;
        case 26: _t->retablir(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
