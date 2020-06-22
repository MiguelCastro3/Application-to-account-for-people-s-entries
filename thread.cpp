#include "thread.h"

Thread::Thread(QObject *parent) : QThread(parent)
{

}

using namespace cv;

void Thread::run()
{
    if (!capture_0.isOpened()) {
        capture_0.open(0); //"abre" câmara, não grava/filma
    }

    //tarefas da câmara 1 - PC
    capture_0.read(frame_0); //grab e retrive num só passo
    if (state == 0) {
        frame_detection = frame_0.clone();
        QImage cam_0_image_out((uchar*)frame_0.data, frame_0.cols, frame_0.rows, QImage::Format_RGB888); //converte Mat em QImage
        emit(camara_0_out(cam_0_image_out)); //envia a imagem da câmara 1
    }
    else { //state == 1, quando ativado o botão de definir região de interesse (on_action_define_region_triggered)                                                           //
        frame_0_region = frame_0.operator()(Range(coordinates[0].y+1, coordinates[1].y), Range(320, 640)); //supposed to be Range(coordinates[0].x+1, coordinates[1].x) but my camera changes the image
                                                                                                           //+1 para apenas incluir o interior da região de interesse, último ponto já é excluído
        copy_frame_0 = frame_0.clone();
        rectangle(copy_frame_0, coordinates[0], coordinates[1], Scalar(255,0,0), 2);
        QImage cam_0_image_out((uchar*)copy_frame_0.data, copy_frame_0.cols, copy_frame_0.rows, QImage::Format_RGB888);
        emit(camara_0_out(cam_0_image_out)); //envia a imagem da câmara 1 com região de interesse definida
        frame_0 = frame_0_region;
        frame_detection = frame_0.clone();
    }

    //DETEÇÃO FACIAL
    //tira foto quando deteta um rosto
    face_cascade.load("haarcascades/haarcascade_frontalface_default.xml");
    cvtColor(frame_0, gray, COLOR_BGR2GRAY); //converte para imagem cinzento, melhor deteção
    equalizeHist(gray, gray); //equalicação do histograma, melhor deteção
    face_cascade.detectMultiScale(gray, faces, 1.3, 5, 0);
    if (int(faces.size()) > number_atual_faces) {
        for (int i = 0; i < int(faces.size()); i++) {
            rectangle(frame_detection, faces[i], Scalar(0,255,0), 2); //cria um retânculo verde em torno da face
        }
        number_people += 1;
        QImage shot_0_image_out((uchar*)frame_detection.data, frame_detection.cols, frame_detection.rows, QImage::Format_RGB888); //converte Mat em QImage
        emit(snapshot_0_out(shot_0_image_out, number_people));
    }
    number_atual_faces = int(faces.size());
}

void Thread::coordinates_region(int number, QVector<cv::Point> vector_point)
{
    state = number;
    coordinates = vector_point;
}
