# -------------------------------------------------
# Project created by QtCreator 2010-02-07T18:35:48
# -------------------------------------------------
QT -= gui
TARGET = example-qdaapd
CONFIG -= app_bundle
TEMPLATE = app

SOURCES +=  main.cpp
HEADERS += fakecollection.h

INCLUDEPATH += ../include
LIBPATH += ..
LIBS += -lqdaapd
