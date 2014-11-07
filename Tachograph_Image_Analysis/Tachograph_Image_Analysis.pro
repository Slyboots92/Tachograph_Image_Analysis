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
    rgb2graylightnessalgo.cpp \
    image.cpp \
    TachoImageShared/tachoimage.cpp \
    tachoimageanalysismain.cpp \
    tachoactivitiy.cpp \
    tachoproccesingmain.cpp \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.cpp \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.cpp \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.cpp \
    GUI/main.cpp \
    GUI/mainwindow.cpp

HEADERS  += mainwindow.h \
    tachoimage.h \
    rgb2graylightnessalgo.h \
    TachoImageShared/tachoimage.h \
    tachoimageanalysismain.h \
    tachoactivitiy.h \
    tachoproccesingmain.h \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.h \
    GUI/mainwindow.h

FORMS    += mainwindow.ui
