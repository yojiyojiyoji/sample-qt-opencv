#include "webcamwindow.h"

WebcamWindow::WebcamWindow(QWidget *parent) :
    QWidget(parent)
{
    this->resize(540,540);
    this->QWidget::setWindowTitle("Webcam Window");
    this->hBoxlayout = new QHBoxLayout();
    this->lbImg = new QLabel("Video from Webcam");
    this->lbImg->setGeometry(20,20,480,480);
    this->hBoxlayout->addWidget(lbImg);
    this->setLayout(hBoxlayout);
}

WebcamWindow::~WebcamWindow()
{
    delete hBoxlayout;
    delete lbImg;
}

void WebcamWindow::setFrame(QPixmap qpxm){
    int w = this->lbImg->width();
    int h = this->lbImg->height();
    this->lbImg->setPixmap(qpxm.scaled(w,h,Qt::KeepAspectRatio));
}
