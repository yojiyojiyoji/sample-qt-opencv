#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Test Results");
}

TestWindow::~TestWindow()
{
    delete ui;
    delete scene;
}

void TestWindow::setText1(QString s){
    ui->lbText1->setText(s);
}

void TestWindow::setText2(QString s){
    ui->lbText2->setText(s);
}

void TestWindow::setImage1(QPixmap qpxm){

    int w = ui->lbImg->width();
    int h = ui->lbImg->height();
    ui->lbImg->setPixmap(qpxm.scaled(w,h,Qt::KeepAspectRatio));
}

void TestWindow::setImage2(QPixmap qpxm){

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addPixmap(qpxm);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
