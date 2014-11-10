#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TachoImageShared/tachoimage.h"
#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.h"
#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/luminosityrgb2grayscale.h"
#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/lightnessrgb2grayscale.h"
#include"TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include"TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysisringimplementation.h"
#include <QDebug>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
