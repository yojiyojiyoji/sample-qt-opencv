#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete iv;
    delete lbImg;
    delete tw1;
    delete tw2;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files(*.png *.jpg *.jpeg *tif)");

    if (!fileName.isEmpty()){
        imgOrigin = cv::imread(fileName.toLatin1().data());
        cvtColor(imgOrigin, imgQt, CV_BGR2RGB);

        QImage tempQImg = QImage(imgQt.data, imgQt.cols, imgQt.rows, imgQt.step, QImage::Format_RGB888);
        QPixmap tempQPM = QPixmap::fromImage(tempQImg);

        lbImg = new QLabel("Original Image");
        lbImg->setGeometry(0,0,480,480);
        int w = lbImg->width();
        int h = lbImg->height();
        lbImg->setPixmap(tempQPM.scaled(w,h,Qt::KeepAspectRatio));
        this->setCentralWidget(lbImg);
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
}

void MainWindow::on_actionFlip_triggered()
{
    if (!imgOrigin.empty()){
        cv::flip(imgOrigin, imgProcessed, 1);
        cvtColor(imgProcessed, imgQt, CV_BGR2RGB);

        iv = new ImageViewer();
        iv->QWidget::setWindowTitle("Processed Image");
        iv->show();

        QImage tempQImg = QImage(imgQt.data, imgQt.cols, imgQt.rows, imgQt.step, QImage::Format_RGB888);
        QPixmap tempQPM = QPixmap::fromImage(tempQImg);
        iv->setImage(tempQPM);
        iv->activateWindow();

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }
}

void MainWindow::on_actionTest01_triggered()
{

}

void MainWindow::on_actionTest02_triggered()
{

}
