QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/src/patient.cpp \
    model/src/adress.cpp \
    model/src/patientlistmodel.cpp \
    view/src/addpatientwidget.cpp \
    view/src/changepatientwidget.cpp \
    view/src/deletedialog.cpp \
    view/src/mainwindow.cpp \
    view/src/showpatientwidget.cpp

HEADERS += \
    model/header/adress.h \
    model/header/gender.h \
    model/header/name.h \
    model/header/patientlistmodel.h \
    model/header/patient.h \
    view/header/addpatientwidget.h \
    view/header/changepatientwidget.h \
    view/header/deletedialog.h \
    view/header/mainwindow.h \
    view/header/showpatientwidget.h

FORMS += \
    view/ui/addpatientwidget.ui \
    view/ui/changepatientwidget.ui \
    view/ui/deletedialog.ui \
    view/ui/mainwindow.ui \
    view/ui/showpatientwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
