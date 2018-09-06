#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>

#include <iostream>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "imageviewer.h"
#include "webcamwindow.h"
#include "testwindow.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    cv::Mat img, imgOrigin, imgProcessed, imgQt;
    cv::Mat vFrame, vFrameOrigin, vFrameProcessed, vFrameQt;
    cv::VideoCapture cap;
    QLabel *lbImg;
    QTimer *timer;
    ImageViewer *iv;
    WebcamWindow *webcamWin;
    TestWindow *tw1, *tw2;

    void update_image_label(cv::Mat img);

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionFlipHorizontal_triggered();
    void on_actionFlipVertical_triggered();
    void on_actionRotate90Clockwise_triggered();
    void on_actionRotate90Counterclockwise_triggered();
    void on_actionOpenWebcamWindow_triggered();
    void on_actionTest01_triggered();
    void on_actionTest02_triggered();

    void play_video();
};

#endif // MAINWINDOW_H
