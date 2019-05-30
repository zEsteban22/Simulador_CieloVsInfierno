#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T22:47:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simulador_CieloVsInfierno
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++1z

SOURCES += \
        arboldeangeles.cpp \
        arboldelmundo.cpp \
        avlcielo.cpp \
        avlfamilia.cpp \
        cielohash.cpp \
        consultarmundo.cpp \
        controller.cpp \
        infierno.cpp \
        listapersonas.cpp \
        main.cpp \
        mainwindow.cpp \
        mapacondegradaciondecolor.cpp \
        mundo.cpp \
        nodoangel.cpp \
        nodoarbol.cpp \
        paraiso.cpp \
        persona.cpp \
        randomxd.cpp \
    consultarcielo.cpp \
    consultarinfierno.cpp

HEADERS += \
        arboldeangeles.h \
        arboldelmundo.h \
        avlcielo.h \
        avlfamilia.h \
        cielohash.h \
        consultarmundo.h \
        controller.h \
        infierno.h \
        listapersonas.h \
        mainwindow.h \
        mapacondegradaciondecolor.h \
        mundo.h \
        nodoangel.h \
        nodoarbol.h \
        nodolista.h \
        paraiso.h \
        persona.h \
        randomxd.h \
    consultarinfierno.h \
    consultarcielo.h

FORMS += \
  consultarinfierno.ui \
        mainwindow.ui \
        mapacondegradaciondecolor.ui \
    consultarmundo.ui \
    consultarcielo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  continentescondegradacion.qrc

# Añadir la librería SMTPEmail
LIBS += -L$$PWD/SMTPEmail/debug/ -lSMTPEmail


INCLUDEPATH += $$PWD/SMTPEmail
DEPENDPATH += $$PWD/SMTPEmail

