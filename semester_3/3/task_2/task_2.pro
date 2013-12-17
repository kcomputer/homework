QT       += core\
            testlib

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += x86 x86_64

TEMPLATE = app

SOURCES += main.cpp \
    counter.cpp

HEADERS += \
    counter.h \
    counterTest.h

