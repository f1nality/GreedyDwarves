#-------------------------------------------------
#
# Project created by QtCreator 2013-11-12T19:58:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GreedyDwarves
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameunit.cpp \
    staticunit.cpp \
    movableunit.cpp \
    baseunit.cpp \
    warriorunit.cpp \
    swordsman.cpp \
    gamecanvas.cpp

HEADERS  += mainwindow.h \
    gameunit.h \
    staticunit.h \
    movableunit.h \
    baseunit.h \
    warriorunit.h \
    swordsman.h \
    gamecanvas.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
