#ifndef CAMERA_H
#define CAMERA_H

#include "thread.h"
#include "mouse_press_event.h"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();
    Thread *thread;

private slots:
    void call_threads();
    void camara_0_out_main(QImage image);
    void snapshot_0_out_main(QImage image, int number);
    void on_action_define_region_triggered();
    void mouse_position_main();

signals:
    void coordinates_region_main(int, QVector<cv::Point>);

private:
    Ui::Camera *ui;
    QTimer *timer;
    QPoint label_coordinates;
    int state = 0;
    cv::Point point;
    QVector<cv::Point> coordinates;
};

#endif // CAMERA_H
