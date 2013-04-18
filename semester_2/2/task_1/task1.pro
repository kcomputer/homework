#-------------------------------------------------
#
# Project created by QtCreator 2013-04-16T02:39:44
#
#-------------------------------------------------

QT       +=        \
             testlib\
               core

QT       -= gui


TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    arrayList.cpp \
    pointerList.cpp

HEADERS += \
    arrayListTest.h \
    pointerListTest.h \
    pointerList.h \
    arraylist.h \
    list.h
