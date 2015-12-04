QT += core
QT -= gui
#comment
TARGET = verklegtnamskeid
CONFIG += console
CONFIG -= app_bundle
QT += sql

TEMPLATE = app

SOURCES += main.cpp \
    sqlite.cpp \
    datalayer.cpp \
    interface.cpp \
    person.cpp \
    worker.cpp

HEADERS += \
    sqlite.h \
    datalayer.h \
    interface.h \
    person.h \
    worker.h

