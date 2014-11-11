#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ImageColorReduction * algo1= new LightnessRGB2GrayScale();

   QImage * image = new  QImage();
   image->load("E:\\qt_workspace\\Tachograph_Image_Analysis\\Resource\\techo1_moja_kadrowana_obrot.jpg" );
   TachoImage * tacho = new TachoImage(image );
   algo1->reduceColor(image,tacho);
   int ** array=tacho->getArray();



    TachoImageAnalysisMain * analysis= new TachoImageAnalysisRingImplementation();
    analysis->getAllActivities(tacho);


int gray;
for(int i=0;i<tacho->getHeight();i++)
{
    for(int j=0;j<tacho->getWidth();j++)
    {
        gray=array[i][j];
        image->setPixel(j, i, qRgb(gray, gray, gray));
    }
}
    QGraphicsScene * scene = new QGraphicsScene();

    QPixmap pixmap = QPixmap::fromImage(*image);
    scene->addPixmap(pixmap);



    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
