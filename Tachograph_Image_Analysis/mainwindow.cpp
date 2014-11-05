#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage * image= new QImage( );
    qDebug()<<image->load("techo1_moja.jpg");
   // qDebug()<<image->load("file:///C:/Users/Slyboots/Pictures/ControlCenter3/Scan/techo1_moja.jpg");
    //image->


   QGraphicsScene * scene = new QGraphicsScene();
   scene->addPixmap(QPixmap::fromImage(*image));
   ui->graphicsView->setScene(scene);
   ui->graphicsView->show();

  //  imageLoader->loadImage("tarcza12.pgm");

}

MainWindow::~MainWindow()
{
    delete ui;
}
