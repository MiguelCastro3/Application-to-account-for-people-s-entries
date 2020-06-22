#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QMainWindow>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

private slots:
    void run();
    void coordinates_region(int, QVector<cv::Point>);

signals:  
    void camara_0_out(QImage);
    void snapshot_0_out(QImage, int);

private:
    cv::VideoCapture capture_0;
    cv::Mat frame_0, frame_detection, gray, frame_0_region, copy_frame_0;
    QImage shot_0_image_out;
    cv::CascadeClassifier face_cascade;
    std::vector<cv::Rect> faces;
    int number_atual_faces = 0, number_people = 0, state = 0;
    QVector<cv::Point> coordinates;
};

#endif // THREAD_H
