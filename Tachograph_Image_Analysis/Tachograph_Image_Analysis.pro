#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T01:31:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tachograph_Image_Analysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tachoimage.cpp \
    rgb2graylightnessalgo.cpp

HEADERS  += mainwindow.h \
    tachoimage.h \
    rgb2grayalgo.h \
    rgb2graylightnessalgo.h

FORMS    += mainwindow.ui
