#-------------------------------------------------
#
# Project created by QtCreator 2013-12-17T18:58:41
#
#-------------------------------------------------

QT       += core\
            testlib

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += x86 x86_64

TEMPLATE = app


SOURCES += main.cpp \
    network.cpp \
    computer.cpp

HEADERS += \
    os.h \
    mac.h \
    linux.h \
    network.h \
    computer.h \
    networkTest.h \
    windows.h \
    randomNumberGeneratorInterface.h \
    randomNumberGenerator.h \
    notRandomNumberGenerator.h
