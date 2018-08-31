#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent)
{
    this->resize(480,480);
    this->QWidget::setWindowTitle("Image Viewer");
    this->hBoxlayout = new QHBoxLayout();
    this->lbImg = new QLabel("Image");
    this->hBoxlayout->addWidget(lbImg);
    this->setLayout(hBoxlayout);
}

ImageViewer::~ImageViewer()
{
    delete hBoxlayout;
    delete lbImg;
}

void ImageViewer::setImage(QPixmap qpxm){
    int w = this->lbImg->width();
    int h = this->lbImg->height();
    this->lbImg->setPixmap(qpxm.scaled(w,h,Qt::KeepAspectRatio));
}
