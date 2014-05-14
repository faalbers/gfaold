#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T23:02:02
#
#-------------------------------------------------

QT       -= gui

TARGET = gfa
TEMPLATE = lib

DEFINES += GFA_LIBRARY

SOURCES += gfa.cpp

HEADERS += gfa.h\
        gfa_global.h

unix {
    target.path = $$PWD/../inst/gfa/lib
    headers.path = $$PWD/../inst/gfa/include
    headers.files = *.h
    INSTALLS += target headers
}

win32 {
    target.path = $$PWD/../inst/gfa/lib
    headers.path = $$PWD/../inst/gfa/include
    headers.files = *.h
    INSTALLS += target headers
}

