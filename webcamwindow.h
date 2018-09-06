#ifndef WEBCAMWINDOW_H
#define WEBCAMWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class WebcamWindow : QWidget
{
    Q_OBJECT
public:
    WebcamWindow();
    ~WebcamWindow();

    void setFrame(QPixmap qpxm);

private:
    QHBoxLayout *hBoxlayout;
    QLabel *lbImg;
};

#endif // WEBCAMWINDOW_H
