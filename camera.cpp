#include "camera.h"
#include "ui_camera.h"

using namespace cv;

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    thread = new Thread();

    //connect sinais
    connect(thread, SIGNAL(camara_0_out(QImage)), this, SLOT(camara_0_out_main(QImage)));
    connect(thread, SIGNAL(snapshot_0_out(QImage, int)), this, SLOT(snapshot_0_out_main(QImage, int)));
    connect(ui->camara_0, SIGNAL(mouse_position()), this, SLOT(mouse_position_main()));
    connect(this, SIGNAL(coordinates_region_main(int, QVector<cv::Point>)), thread, SLOT(coordinates_region(int, QVector<cv::Point>)));

    timer = new QTimer; //define um temporizador
    connect(timer, SIGNAL(timeout()), this, SLOT(call_threads())); //chama função para ler e converter câmara para a QLabel
    timer->start(0);
}

Camera::~Camera()
{
    delete ui;
}

void Camera::call_threads()
{
    thread->start();
}

void Camera::camara_0_out_main(QImage image)
{
    ui->camara_0->setPixmap(QPixmap::fromImage(image));
}

void Camera::snapshot_0_out_main(QImage image, int number)
{
    QImage resize_image = image.scaled(640, 480, Qt::KeepAspectRatio);
    ui->snapshot_0->setPixmap(QPixmap::fromImage(resize_image));
    ui->people_ui->setText(QString("NÚMERO DE PESSOAS QUE ENTRARAM: %1").arg(number));
}

void Camera::on_action_define_region_triggered()
{
    state = 1; //variável de estado
    coordinates.clear(); //limpar coordenadas anteriores quando precisar de definir uma nova região
}

void Camera::mouse_position_main()
{
    if (state == 1) { //só quando carregar na toolbar => definir região de interesse
        point = Point(ui->camara_0->x, ui->camara_0->y);
        coordinates << point;
        if (coordinates.size() == 2) {
            emit(coordinates_region_main(state, coordinates));
            state = 0; //mouse press event deixa de "trabalhar", ou seja, não contribui para o codigo na thread
        }
    }
}
