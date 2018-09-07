#ifndef WEBCAMWINDOW_H
#define WEBCAMWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class WebcamWindow : public QWidget
{
    Q_OBJECT

public:
    WebcamWindow(QWidget *parent = nullptr);
    ~WebcamWindow();

    void setFrame(QPixmap qpxm);

private:
    QHBoxLayout *hBoxlayout;
    QLabel *lbImg;
};

#endif // WEBCAMWINDOW_H
