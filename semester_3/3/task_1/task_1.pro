QT       += core\
            testlib

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += x86 x86_64

TEMPLATE = app

HEADERS += \
    GraphWithRobots.h \
    GraphWithRobotsTest.h

SOURCES += \
    main.cpp \
    GraphWithRobots.cpp

OTHER_FILES += \
    Graph_1.txt \
    Graph_2.txt
