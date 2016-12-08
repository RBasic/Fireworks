#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T23:30:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fireworks
TEMPLATE = app

SOILPATH = "c:/Simple OpenGL Image Library"
INCLUDEPATH += "$${SOILPATH}/src"
LIBS += -L"$$(SOILPATH)/lib" -lSOIL
LIBS += -lOpenGL32

SOURCES += main.cpp\
    firework.cpp \
    openglwindow.cpp \
    fireworkwindow.cpp

HEADERS  += \
    firework.h \
    openglwindow.h \
    fireworkwindow.h
