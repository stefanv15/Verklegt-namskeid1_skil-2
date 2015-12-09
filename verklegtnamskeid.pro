QT += core
QT += sql
QT -= gui
#comment
TARGET = verklegtnamskeid
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp
SOURCES += sqlite.cpp
SOURCES +=
SOURCES += interface.cpp
SOURCES += person.cpp
SOURCES += computers.cpp
SOURCES += comp_pers.cpp
SOURCES += domain.cpp

HEADERS += \
    sqlite.h \
    interface.h \
    person.h \
    computers.h \
    comp_pers.h \
    domain.h

