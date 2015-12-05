QT += core
QT += sql
QT -= gui
#comment
TARGET = verklegtnamskeid
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    sqlite.cpp \
    datalayer.cpp \
    interface.cpp \
    person.cpp \
    worker.cpp \
    computers.cpp \
    comp_pers.cpp

HEADERS += \
    sqlite.h \
    datalayer.h \
    interface.h \
    person.h \
    worker.h \
    computers.h \
    comp_pers.h

