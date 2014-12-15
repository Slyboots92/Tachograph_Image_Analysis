#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ImageColorReduction * algo1= new LightnessRGB2GrayScale();

   QImage * image = new  QImage();
   image->load("D:\\development\\workspaces\\qt_workspace\\engineer\\Tachograph_Image_Analysis\\Tachograph_Image_Analysis\\Resource\\techo1_moja_kadrowana_obrot.jpg");
   //image->load("E:\\qt_workspace\\Tachograph_Image_Analysis\\Resource\\techo1_moja_kadrowana_obrot.jpg" );
   TachoImage * tacho = new TachoImage(image );
   algo1->reduceColor(image,tacho);
   int ** array=tacho->getArray();
   tacho->setActivityExternalRadius(387);
   tacho->setActivityInternalRadius(363);
   tacho->setXCenterCord(tacho->getWidth()/2);
   tacho->setYCenterCord(tacho->getHeight()/2);
   // int a=tacho->getHeight()/2;
   // int b=tacho->getWidth()/2;
    //int r1=363;
    //int r2=387;


    TachoImageAnalysisMain * analysis= new TachoImageAnalysisPolarImplementation();
    int *result=analysis->getAllActivities(tacho);
    int x;
    int y;
    int counter=0;

//Change grayscale to RGB to display
int gray;
for(int i=0;i<tacho->getHeight();i++)
{
    for(int j=0;j<tacho->getWidth();j++)
    {
        gray=array[i][j];
        image->setPixel(j, i, qRgb(gray, gray, gray));
    }
}
for(int i=180*2;i>-180*2;i--)
{
     for(int k=0;k<=tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius();k++)
     {
         x=round((tacho->getActivityInternalRadius()+k)*cos( M_PI*i/(180*2)));
         y=round((tacho->getActivityInternalRadius()+k)*sin( M_PI*i/(180*2)));
         y=y+tacho->getXCenterCord();
         x=x+tacho->getYCenterCord();
         if(result[counter]==0)
         {
                image->setPixel(y, x, qRgb(255, 0, 0));
         }
         else if(result[counter]==1)
         {
                image->setPixel(y, x, qRgb(0, 0, 255));
         }
         else if(result[counter]==2)
         {
                image->setPixel(y, x, qRgb(0, 255, 0));
         }
         else if(result[counter]==3)
         {
            image->setPixel(y, x, qRgb(255, 255, 0));
         }
         //array[y][x]=0;

     }
     counter++;
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
