#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T20:09:44
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = PreForkServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    incomingconnection.cpp

HEADERS += \
    incomingconnection.h
