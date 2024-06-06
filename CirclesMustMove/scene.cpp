#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
    , center(100,100)
    , center2(200,200)
    , center3(200,200)
    , center4(200,200)
    , radius(30)
{
    setSceneRect(0,0,400,400);
}

void Scene::paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color){
    painter->setBrush(color);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(centerEllipse,radius,radius);
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->fillRect(sceneRect(),Qt::white);

    this->paintEllipse(painter, center, Qt::blue);
    this->paintEllipse(painter, center2, Qt::green);
    this->paintEllipse(painter, center3, Qt::red);
    this->paintEllipse(painter, center4, Qt::yellow);
}


QPointF Scene::setCenter(int &angle, QGraphicsSceneMouseEvent *event){
    double newX;
    double newY;
    if(press.x() <= event->scenePos().x()){
        qDebug() << "right";
        angle += 10;
        if (angle >= 360) angle -= 360;
        if (angle2 >= 360) angle2 -= 360;

        double radians = angle * M_PI / 180;
        newX = 100 + 60  * cos(radians);
        newY = 100 + 60  * sin(radians);
    }
    else{
        qDebug() << "left";
        angle -= 10;
        if (angle <= -360) angle += 360;
        if (angle2 <= -360) angle2 += 360;

        double radians = angle * M_PI / 180;
        newX = 100 + 60  * cos(radians);
        newY = 100 + 60  * sin(radians);
    }
    return QPointF(newX, newY);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    center = this->setCenter(angle, event);
    center2 = this->setCenter(angle2, event);
    center3 = this->setCenter(angle3, event);
    center4 = this->setCenter(angle4, event);
    update();
    qDebug() << "update";
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    press = event->scenePos();

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}
