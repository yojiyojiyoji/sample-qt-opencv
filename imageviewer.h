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

    void setImage(QPixmap qpxm);

private:
    QHBoxLayout *hBoxlayout;
    QLabel *lbImg;
};

#endif // IMAGEVIEWER_H
