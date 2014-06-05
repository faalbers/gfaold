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
    rgbcolor.cpp \
    point3d.cpp \
    vector3d.cpp \
    point2d.cpp \
    normal.cpp

HEADERS += gfa.h\
        gfa_global.h \
    rgbcolorbuffer.h \
    rgbcolor.h \
    point3d.h \
    vector3d.h \
    point2d.h \
    normal.h

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -fvisibility=hidden

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

