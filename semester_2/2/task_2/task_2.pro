#-------------------------------------------------
#
# Project created by QtCreator 2013-04-19T00:38:59
#
#-------------------------------------------------

QT       += core\
            testlib\

QT       -= gui

TARGET = task_2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    stackMachine.cpp \
    pointerStackInt.cpp \
    arrayStackInt.cpp

HEADERS += \
    stackMachine.h \
    stackInt.h \
    pointerStackInt.h \
    pointerStackCalculatorTest.h \
    arrayStackInt.h \
    arrayStackCalculatorTest.h
