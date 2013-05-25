#-------------------------------------------------
#
# Project created by QtCreator 2013-05-26T00:50:53
#
#-------------------------------------------------

QT       += core\
        testlib

QT       -= gui

TARGET = task_1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    stringList.cpp \
    mySecondHashFunction.cpp \
    myHashFunction.cpp \
    changeableHash.cpp

HEADERS += \
    stringList.h \
    mySecondHashFunction.h \
    myHashFunction.h \
    interactivePart.h \
    hashFunction.h \
    hash.h \
    changeableHashTest.h \
    changeableHash.h
