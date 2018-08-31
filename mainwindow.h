#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "imageviewer.h"
#include "testwindow.h"

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
    cv::Mat imgOrigin, imgProcessed, imgQt;
    QLabel *lbImg;
    ImageViewer *iv;
    TestWindow *tw1, *tw2;

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionFlip_triggered();
    void on_actionTest01_triggered();
    void on_actionTest02_triggered();
};

#endif // MAINWINDOW_H
