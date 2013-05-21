#-------------------------------------------------
#
# Project created by QtCreator 2013-05-21T14:58:36
#
#-------------------------------------------------

QT       += core\
        testlib

QT       -= gui

TARGET = task_2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    spiralPrinter.cpp \
    fileSpiralPriter.cpp \
    consoleSpiralPrinter.cpp

OTHER_FILES += \
    output.txt

HEADERS += \
    spiralPrinter.h \
    printerTest.h \
    fileSpiralPrinter.h \
    consoleSpiralPrinter.h \
    abstractSpiralPrinter.h
