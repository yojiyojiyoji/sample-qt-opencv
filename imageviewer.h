#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

private:
    QHBoxLayout *hBoxlayout;
    QLabel *lbImg;

public:
    void setImage(QPixmap qpxm);

};

#endif // IMAGEVIEWER_H
