QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IsoCustomizeTool
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    selectiso.cpp \
    structure.cpp \
    appconfiguration.cpp \
    prepare.cpp \
    midinstall.cpp \
    postcleaning.cpp \
    selectkernel.cpp \
    output.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    selectiso.h \
    structure.h \
    appconfiguration.h \
    prepare.h \
    midinstall.h \
    postcleaning.h \
    selectkernel.h \
    output.h

DISTFILES += \
    number/NO_inactive1.svg \
    number/NO_inactive3.svg \
    number/NO_inactive4.svg \
    number/NO_inactive5.svg \
    number/NO_inactive6.svg \
    number/NO_inactive7.svg \
    number/NO_inactive8.svg \
    number/NO_inactive9.svg
