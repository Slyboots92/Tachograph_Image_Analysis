
#include <QApplication>
#include "GUI/mainwindow.h"
#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
     w.show();

   // ImageColorReduction *algo2=new AverageRGB2GrayScale();
    //TachoImage *tacho = new TachoImage()

    return a.exec();
}
