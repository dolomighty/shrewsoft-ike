/****************************************************************************
** Meta object code from reading C++ file 'qikea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qikea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qikea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata__qikeaRoot_t {
    QByteArrayData data[16];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__qikeaRoot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__qikeaRoot_t qt_meta_stringdata__qikeaRoot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "_qikeaRoot"
QT_MOC_LITERAL(1, 11, 13), // "showViewLarge"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "showViewSmall"
QT_MOC_LITERAL(4, 40, 11), // "siteContext"
QT_MOC_LITERAL(5, 52, 3), // "pos"
QT_MOC_LITERAL(6, 56, 11), // "siteConnect"
QT_MOC_LITERAL(7, 68, 7), // "siteAdd"
QT_MOC_LITERAL(8, 76, 10), // "siteModify"
QT_MOC_LITERAL(9, 87, 10), // "siteDelete"
QT_MOC_LITERAL(10, 98, 10), // "siteRename"
QT_MOC_LITERAL(11, 109, 11), // "siteRenamed"
QT_MOC_LITERAL(12, 121, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(13, 138, 10), // "siteImport"
QT_MOC_LITERAL(14, 149, 10), // "siteExport"
QT_MOC_LITERAL(15, 160, 9) // "showAbout"

    },
    "_qikeaRoot\0showViewLarge\0\0showViewSmall\0"
    "siteContext\0pos\0siteConnect\0siteAdd\0"
    "siteModify\0siteDelete\0siteRename\0"
    "siteRenamed\0QListWidgetItem*\0siteImport\0"
    "siteExport\0showAbout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__qikeaRoot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void _qikeaRoot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<_qikeaRoot *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showViewLarge(); break;
        case 1: _t->showViewSmall(); break;
        case 2: _t->siteContext((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->siteConnect(); break;
        case 4: _t->siteAdd(); break;
        case 5: _t->siteModify(); break;
        case 6: _t->siteDelete(); break;
        case 7: _t->siteRename(); break;
        case 8: _t->siteRenamed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->siteImport(); break;
        case 10: _t->siteExport(); break;
        case 11: _t->showAbout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject _qikeaRoot::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata__qikeaRoot.data,
    qt_meta_data__qikeaRoot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_qikeaRoot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_qikeaRoot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__qikeaRoot.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::qikeaRoot"))
        return static_cast< Ui::qikeaRoot*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int _qikeaRoot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
struct qt_meta_stringdata__qikeaSite_t {
    QByteArrayData data[26];
    char stringdata0[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__qikeaSite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__qikeaSite_t qt_meta_stringdata__qikeaSite = {
    {
QT_MOC_LITERAL(0, 0, 10), // "_qikeaSite"
QT_MOC_LITERAL(1, 11, 6), // "verify"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "policyAdd"
QT_MOC_LITERAL(4, 29, 12), // "policyModify"
QT_MOC_LITERAL(5, 42, 12), // "policyDelete"
QT_MOC_LITERAL(6, 55, 18), // "updateConfigMethod"
QT_MOC_LITERAL(7, 74, 17), // "updateAddressAuto"
QT_MOC_LITERAL(8, 92, 19), // "updateAddressMethod"
QT_MOC_LITERAL(9, 112, 13), // "updateGeneral"
QT_MOC_LITERAL(10, 126, 5), // "adflt"
QT_MOC_LITERAL(11, 132, 5), // "mdflt"
QT_MOC_LITERAL(12, 138, 12), // "updateClient"
QT_MOC_LITERAL(13, 151, 20), // "updateNameResolution"
QT_MOC_LITERAL(14, 172, 16), // "updateAuthMethod"
QT_MOC_LITERAL(15, 189, 20), // "updateAuthentication"
QT_MOC_LITERAL(16, 210, 13), // "updateLocalID"
QT_MOC_LITERAL(17, 224, 14), // "updateRemoteID"
QT_MOC_LITERAL(18, 239, 12), // "updatePhase1"
QT_MOC_LITERAL(19, 252, 12), // "updatePhase2"
QT_MOC_LITERAL(20, 265, 12), // "updatePolicy"
QT_MOC_LITERAL(21, 278, 13), // "selectLocalID"
QT_MOC_LITERAL(22, 292, 14), // "selectRemoteID"
QT_MOC_LITERAL(23, 307, 11), // "inputCAFile"
QT_MOC_LITERAL(24, 319, 13), // "inputCertFile"
QT_MOC_LITERAL(25, 333, 13) // "inputPKeyFile"

    },
    "_qikeaSite\0verify\0\0policyAdd\0policyModify\0"
    "policyDelete\0updateConfigMethod\0"
    "updateAddressAuto\0updateAddressMethod\0"
    "updateGeneral\0adflt\0mdflt\0updateClient\0"
    "updateNameResolution\0updateAuthMethod\0"
    "updateAuthentication\0updateLocalID\0"
    "updateRemoteID\0updatePhase1\0updatePhase2\0"
    "updatePolicy\0selectLocalID\0selectRemoteID\0"
    "inputCAFile\0inputCertFile\0inputPKeyFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__qikeaSite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x08 /* Private */,
       3,    0,  125,    2, 0x08 /* Private */,
       4,    0,  126,    2, 0x08 /* Private */,
       5,    0,  127,    2, 0x08 /* Private */,
       6,    0,  128,    2, 0x08 /* Private */,
       7,    0,  129,    2, 0x08 /* Private */,
       8,    0,  130,    2, 0x08 /* Private */,
       9,    2,  131,    2, 0x08 /* Private */,
      12,    0,  136,    2, 0x08 /* Private */,
      13,    0,  137,    2, 0x08 /* Private */,
      14,    0,  138,    2, 0x08 /* Private */,
      15,    0,  139,    2, 0x08 /* Private */,
      16,    0,  140,    2, 0x08 /* Private */,
      17,    0,  141,    2, 0x08 /* Private */,
      18,    0,  142,    2, 0x08 /* Private */,
      19,    0,  143,    2, 0x08 /* Private */,
      20,    0,  144,    2, 0x08 /* Private */,
      21,    0,  145,    2, 0x08 /* Private */,
      22,    0,  146,    2, 0x08 /* Private */,
      23,    0,  147,    2, 0x08 /* Private */,
      24,    0,  148,    2, 0x08 /* Private */,
      25,    0,  149,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void _qikeaSite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<_qikeaSite *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->verify();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->policyAdd(); break;
        case 2: _t->policyModify(); break;
        case 3: _t->policyDelete(); break;
        case 4: _t->updateConfigMethod(); break;
        case 5: _t->updateAddressAuto(); break;
        case 6: _t->updateAddressMethod(); break;
        case 7: _t->updateGeneral((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->updateClient(); break;
        case 9: _t->updateNameResolution(); break;
        case 10: _t->updateAuthMethod(); break;
        case 11: _t->updateAuthentication(); break;
        case 12: _t->updateLocalID(); break;
        case 13: _t->updateRemoteID(); break;
        case 14: _t->updatePhase1(); break;
        case 15: _t->updatePhase2(); break;
        case 16: _t->updatePolicy(); break;
        case 17: _t->selectLocalID(); break;
        case 18: _t->selectRemoteID(); break;
        case 19: _t->inputCAFile(); break;
        case 20: _t->inputCertFile(); break;
        case 21: _t->inputPKeyFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject _qikeaSite::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata__qikeaSite.data,
    qt_meta_data__qikeaSite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_qikeaSite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_qikeaSite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__qikeaSite.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::qikeaSite"))
        return static_cast< Ui::qikeaSite*>(this);
    return QDialog::qt_metacast(_clname);
}

int _qikeaSite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
struct qt_meta_stringdata__qikeaConflict_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__qikeaConflict_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__qikeaConflict_t qt_meta_stringdata__qikeaConflict = {
    {
QT_MOC_LITERAL(0, 0, 14) // "_qikeaConflict"

    },
    "_qikeaConflict"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__qikeaConflict[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void _qikeaConflict::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject _qikeaConflict::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata__qikeaConflict.data,
    qt_meta_data__qikeaConflict,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_qikeaConflict::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_qikeaConflict::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__qikeaConflict.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::qikeaConflict"))
        return static_cast< Ui::qikeaConflict*>(this);
    return QDialog::qt_metacast(_clname);
}

int _qikeaConflict::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata__qikeaTopology_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__qikeaTopology_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__qikeaTopology_t qt_meta_stringdata__qikeaTopology = {
    {
QT_MOC_LITERAL(0, 0, 14), // "_qikeaTopology"
QT_MOC_LITERAL(1, 15, 6), // "verify"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "_qikeaTopology\0verify\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__qikeaTopology[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void _qikeaTopology::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<_qikeaTopology *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->verify();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject _qikeaTopology::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata__qikeaTopology.data,
    qt_meta_data__qikeaTopology,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_qikeaTopology::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_qikeaTopology::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__qikeaTopology.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::qikeaTopology"))
        return static_cast< Ui::qikeaTopology*>(this);
    return QDialog::qt_metacast(_clname);
}

int _qikeaTopology::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata__qikeaAbout_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__qikeaAbout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__qikeaAbout_t qt_meta_stringdata__qikeaAbout = {
    {
QT_MOC_LITERAL(0, 0, 11) // "_qikeaAbout"

    },
    "_qikeaAbout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__qikeaAbout[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void _qikeaAbout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject _qikeaAbout::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata__qikeaAbout.data,
    qt_meta_data__qikeaAbout,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_qikeaAbout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_qikeaAbout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__qikeaAbout.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::qikeaAbout"))
        return static_cast< Ui::qikeaAbout*>(this);
    return QDialog::qt_metacast(_clname);
}

int _qikeaAbout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
