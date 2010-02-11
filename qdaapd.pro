# -------------------------------------------------
# Project created by QtCreator 2010-02-07T18:35:48
# -------------------------------------------------
# QT += network
QT -= gui
OBJECTS_DIR = build
MOC_DIR = build
TARGET = qdaapd
CONFIG += staticlib
CONFIG -= app_bundle
TEMPLATE = lib

INCLUDEPATH += daaplib/include
INCLUDEPATH += include
INCLUDEPATH += src

SOURCES +=  src/mongoose.c \
            src/qdaapd.cpp \
            src/registry.cpp \
            src/taginput.cpp \
            src/tagoutput.cpp

HEADERS +=  include/qdaapd/qdaapd.h \
            include/qdaapd/collection.h \
            include/qdaapd/mongoose.h \
            include/qdaapd/basic.h \
            include/qdaapd/registry.h \
            include/qdaapd/taginput.h \
            include/qdaapd/tagoutput.h


#TARGET = qdaapd
#CONFIG += staticlib
#TEMPLATE = lib
#TARGET = qdaap
