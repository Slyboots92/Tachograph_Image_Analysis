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
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysisringimplementation.cpp \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysispolarimplementation.cpp \
    TachoImageAnalysis/TachoActivities/tachodrivingactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachoworkingactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachostandbyactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachorestactivity.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/averagergb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/imagecolorreduction.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/lightnessrgb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/luminosityrgb2grayscale.cpp




HEADERS  += \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.h \
    TachoImageShared/tachoimage.h \
    GUI/mainwindow.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysisringimplementation.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysispolarimplementation.h \
    TachoImageAnalysis/TachoActivities/tachodrivingactivity.h \
    TachoImageAnalysis/TachoActivities/tachoworkingactivity.h \
    TachoImageAnalysis/TachoActivities/tachostandbyactivity.h \
    TachoImageAnalysis/TachoActivities/tachorestactivity.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/averagergb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/imagecolorreduction.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/lightnessrgb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/luminosityrgb2grayscale.h






OTHER_FILES += \
    Resource/techo1_moja.jpg \
    Resource/tarcza12.pgm \
    Resource/techo1_moja_kadrowana.jpg \
    Resource/techo1_moja_kadrowana_obrot.jpg

FORMS += \
    GUI/mainwindow.ui
