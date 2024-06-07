#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
    , center(100,100)
    , center2(100,100)
    , center3(100,100)
    , center4(100,100)
    , center5(100,100)
{
    setSceneRect(0,0,400,400);
}

void Scene::paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color, int diameter){
    painter->setBrush(color);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(centerEllipse,diameter,diameter);
}

void Scene::paintCenter(QPainter *painter, QPointF centerEllipse, int diameter, int angle){
    int angle1 = (angle + 0) * 16;
    int angle2 = (angle + 90) * 16;
    int angle3 = (angle + 180) * 16;
    int angle4 = (angle + 270) * 16;

    painter->setBrush(Qt::red);
    painter->setPen(Qt::SolidLine);
    painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle1, 90 * 16);

    painter->setBrush(Qt::green);
    painter->setPen(Qt::SolidLine);
    painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle2, 90 * 16);

    painter->setBrush(Qt::blue);
    painter->setPen(Qt::SolidLine);
    painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle3, 90 * 16);

    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::SolidLine);
    painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle4, 90 * 16);
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->fillRect(sceneRect(),Qt::white);

    this->paintEllipse(painter, center, Qt::blue);
    this->paintCenter(painter, center, 10, angle);
    this->paintEllipse(painter, center2, Qt::green);
    this->paintCenter(painter, center2, 10, angle);
    this->paintEllipse(painter, center3, Qt::red);
    this->paintCenter(painter, center3, 10, angle);
    this->paintEllipse(painter, center4, Qt::yellow);
    this->paintCenter(painter, center4, 10, angle);
    this->paintEllipse(painter, center5, Qt::gray);
    this->paintCenter(painter, center5, 10, angle);
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
    center5 = this->setCenter(angle5, event);
    update();
    qDebug() << "update";
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    press = event->scenePos();

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}
