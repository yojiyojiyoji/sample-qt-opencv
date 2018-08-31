#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class TestWindow;
}

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow();

    void setText1(QString s);
    void setText2(QString s);
    void setImage1(QPixmap qpxm);
    void setImage2(QPixmap qpxm);

private:
    Ui::TestWindow *ui;
    QGraphicsScene *scene;
};

#endif // TESTWINDOW_H
