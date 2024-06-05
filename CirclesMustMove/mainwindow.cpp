#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , center(100,100)
    , center2(200,200)
    , radius(30)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::green);
    painter.drawEllipse(center,radius,radius);
    painter.setBrush(Qt::red);
    painter.drawEllipse(center2,radius,radius);
}


QPoint MainWindow::setCenter(int angle){
    angle += 10; // Увеличиваем угол (можно изменить шаг угла по вашему усмотрению)
    if (angle >= 360) angle -= 360; // Угол должен оставаться в пределах 0-360 градусов

    // Переводим угол в радианы для использования в математических функциях
    double radians = angle * M_PI / 180;

    // Рассчитываем новые координаты по окружности
    double newX = 100 + 60  * cos(radians);
    double newY = 100 + 60  * sin(radians);
    return QPoint(newX, newY);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    angle += 10; // Увеличиваем угол (можно изменить шаг угла по вашему усмотрению)
    if (angle >= 360) angle -= 360; // Угол должен оставаться в пределах 0-360 градусов

    // Переводим угол в радианы для использования в математических функциях
    double radians = angle * M_PI / 180;

    // Рассчитываем новые координаты по окружности
    double newX = 100 + 60  * cos(radians);
    double newY = 100 + 60  * sin(radians);
    center = QPoint(newX, newY);
    //center2 = this->setCenter(50);
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event){

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){

}
