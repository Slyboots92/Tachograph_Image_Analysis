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
    TachoImageAnalysis/TachoActivities/tachoactivitiy.cpp \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.cpp \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.cpp \
    TachoImageShared/tachoimage.cpp \
    GUI/mainwindow.cpp \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/imagecolorreduction.cpp \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/lightnessrgb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/luminosityrgb2grayscale.cpp



HEADERS  += \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.h \
    TachoImageShared/tachoimage.h \
    GUI/mainwindow.h \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/imagecolorreduction.h \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/lightnessrgb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/luminosityrgb2grayscale.h





OTHER_FILES += \
    Resource/techo1_moja.jpg \
    Resource/tarcza12.pgm

FORMS += \
    GUI/mainwindow.ui
