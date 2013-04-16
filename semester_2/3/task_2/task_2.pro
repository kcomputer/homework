TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    consoleSpiralPrinter.cpp \
    fileSpiralPriter.cpp

HEADERS += \
    spiralPrinter.h \
    consoleSpiralPrinter.h \
    fileSpiralPrinter.h

OTHER_FILES += \
    output.txt

