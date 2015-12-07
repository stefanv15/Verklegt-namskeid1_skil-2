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
    computers.cpp \
    comp_pers.cpp \
    domain.cpp

HEADERS += \
    sqlite.h \
    datalayer.h \
    interface.h \
    person.h \
    computers.h \
    comp_pers.h \
    domain.h

