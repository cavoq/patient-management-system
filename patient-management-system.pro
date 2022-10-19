QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/src/address.cpp \
    model/src/patient.cpp \
    model/src/patienttablemodel.cpp \
    multicolumnfilterproxymodel.cpp \
    patientjsonreader.cpp \
    patientjsonwriter.cpp \
    view/src/changepatientwidget.cpp \
    view/src/deletedialog.cpp \
    view/src/mainwindow.cpp \
    view/src/showpatientwidget.cpp \
    view/src/patientformwidget.cpp

HEADERS += \
    model/header/address.h \
    model/header/name.h \
    model/header/patient.h \
    model/header/patienttablemodel.h \
    multicolumnfilterproxymodel.h \
    patientjsonreader.h \
    patientjsonwriter.h \
    view/header/changepatientwidget.h \
    view/header/deletedialog.h \
    view/header/mainwindow.h \
    view/header/showpatientwidget.h \
    view/header/patientformwidget.h

FORMS += \
    view/ui/deletedialog.ui \
    view/ui/mainwindow.ui \
    view/ui/patientformwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
