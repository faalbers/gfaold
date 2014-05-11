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
    target.path = /usr/lib
    INSTALLS += target
}
