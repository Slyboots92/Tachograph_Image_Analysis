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
    GUI/mainwindow.cpp \
    TachoImageAnalysis/PolarBasicImpl/tachoimageanalysispolarimplementation.cpp \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.cpp \
    TachoImageAnalysis/TachoActivities/tachodrivingactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachorestactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachostandbyactivity.cpp \
    TachoImageAnalysis/TachoActivities/tachoworkingactivity.cpp \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.cpp \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysisringimplementation.cpp \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/averagergb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/imagecolorreduction.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/lightnessrgb2grayscale.cpp \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/luminosityrgb2grayscale.cpp \
    TachoImageShared/tachoimage.cpp \
    TachoImageProccesing/ColorReduction/averagergb2grayscale.cpp \
    TachoImageProccesing/ColorReduction/imagecolorreduction.cpp \
    TachoImageProccesing/ColorReduction/lightnessrgb2grayscale.cpp \
    TachoImageProccesing/ColorReduction/luminosityrgb2grayscale.cpp \
    TachoImageProccesing/tachoproccesingmain.cpp




HEADERS  += \
    GUI/mainwindow.h \
    TachoImageAnalysis/PolarBasicImpl/tachoimageanalysispolarimplementation.h \
    TachoImageAnalysis/TachoActivities/tachoactivitiy.h \
    TachoImageAnalysis/TachoActivities/tachodrivingactivity.h \
    TachoImageAnalysis/TachoActivities/tachorestactivity.h \
    TachoImageAnalysis/TachoActivities/tachostandbyactivity.h \
    TachoImageAnalysis/TachoActivities/tachoworkingactivity.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h \
    TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysisringimplementation.h \
    TachoImageProccesing/TachoProccesingLogic/tachoproccesingmain.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/averagergb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/imagecolorreduction.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/lightnessrgb2grayscale.h \
    TachoImageProccesing/TachoProccesingLogic/ColorReduction/luminosityrgb2grayscale.h \
    TachoImageShared/tachoimage.h \
    TachoImageProccesing/ColorReduction/averagergb2grayscale.h \
    TachoImageProccesing/ColorReduction/imagecolorreduction.h \
    TachoImageProccesing/ColorReduction/lightnessrgb2grayscale.h \
    TachoImageProccesing/ColorReduction/luminosityrgb2grayscale.h \
    TachoImageProccesing/tachoproccesingmain.h





OTHER_FILES += \
    Resource/techo1_moja.jpg \
    Resource/tarcza12.pgm \
    Resource/techo1_moja_kadrowana.jpg \
    Resource/techo1_moja_kadrowana_obrot.jpg

FORMS += \
    GUI/mainwindow.ui
