#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T23:02:02
#
#-------------------------------------------------

QT       -= gui

TARGET = gfa
TEMPLATE = lib

DEFINES += GFA_LIBRARY

SOURCES += gfa.cpp \
    rgbcolorbuffer.cpp \
    rgbcolor.cpp

HEADERS += gfa.h\
        gfa_global.h \
    rgbcolorbuffer.h \
    rgbcolor.h

CONFIG += c++11

unix {
    target.path = $$PWD/../inst/lib
    headers.path = $$PWD/../inst/include/gfa
    headers.files = *.h
    INSTALLS += target headers
}

win32 {
    target.path = $$PWD/../inst/lib
    headers.path = $$PWD/../inst/include/gfa
    headers.files = *.h
    INSTALLS += target headers
}

