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
        img = cv::imread(fileName.toLatin1().data());
        this->update_image_label(img);
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
}

void MainWindow::on_actionFlipHorizontal_triggered()
{
    if (!img.empty()){
        cv::flip(img, img, 0); // horizontal flip
        this->update_image_label(img);
    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }
}

void MainWindow::on_actionFlipVertical_triggered()
{
    if (!img.empty()){
        cv::flip(img, img, 1); // vertical flip
        this->update_image_label(img);
    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }
}

void MainWindow::on_actionRotate90Clockwise_triggered()
{
    if (!img.empty()){
        cv::transpose(img, img);
        cv::flip(img, img, 1); // vertical flip
        this->update_image_label(img);
    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }
}

void MainWindow::on_actionRotate90Counterclockwise_triggered()
{
    if (!img.empty()){
        cv::transpose(img, img);
        cv::flip(img, img, 0); // horizontal flip
        this->update_image_label(img);
    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }
}

void MainWindow::on_actionOpenWebcamWindow_triggered()
{
    if(!cap.open(0)){
        QMessageBox::warning(this, "Error Ocurred", "Please check if the webcam is properly setup.");
    }
    else{
        webcamWin = new WebcamWindow();
        timer = new QTimer();
        this->QObject::connect(timer, SIGNAL(timeout()), this , SLOT(play_video()));
        timer->start(100);
    }
}

void MainWindow::update_image_label(cv::Mat img){
    cvtColor(img, imgQt, CV_BGR2RGB);

    QImage tempQImg = QImage(imgQt.data, imgQt.cols, imgQt.rows, imgQt.step, QImage::Format_RGB888);
    QPixmap tempQPM = QPixmap::fromImage(tempQImg);

    lbImg = new QLabel("Rotated Image (90 degree colockwise)");
    lbImg->setGeometry(0,0,480,480);
    int w = lbImg->width();
    int h = lbImg->height();
    lbImg->setPixmap(tempQPM.scaled(w,h,Qt::KeepAspectRatio));
    this->setCentralWidget(lbImg);
}

void MainWindow::play_video(){
        cap >> vFrameOrigin;
        cvtColor(vFrameOrigin, vFrameQt, CV_BGR2RGB);
        QImage tempFrame = QImage(vFrameQt.data, vFrameQt.cols, vFrameQt.rows, vFrameQt.step, QImage::Format_RGB888);
        QPixmap tempQPM = QPixmap::fromImage(tempFrame);
        lbImg = new QLabel("Video from Webcam");
        lbImg->setGeometry(0,0,480,480);
        int w = lbImg->width();
        int h = lbImg->height();
        webcamWin->setFrame(tempQPM);
}


void MainWindow::on_actionTest01_triggered(){

}

void MainWindow::on_actionTest02_triggered(){

}
