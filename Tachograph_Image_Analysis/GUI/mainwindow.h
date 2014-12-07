#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include "TachoImageShared/tachoimage.h"
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include "TachoImageAnalysis/PolarBasicImpl/tachoimageanalysispolarimplementation.h"
#include "TachoImageProccesing/ColorReduction/imagecolorreduction.h"
#include "TachoImageProccesing/ColorReduction/averagergb2grayscale.h"
#include "TachoImageProccesing/ColorReduction/lightnessrgb2grayscale.h"

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
