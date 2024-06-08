#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0,0,sizeScene,sizeScene);
    for (int i = 0; i < countCircles; ++i) {
        if(i < 6){
        double radians = fillDegree/countInCircles*i * M_PI / (fillDegree/2);
        double newX = center.x() + radius  * cos(radians);
        double newY = center.y() + radius  * sin(radians);
        centersList.append(QPointF(newX , newY));
        listForParking.append(QPointF(newX , newY));
        anglesList.append(fillDegree/countInCircles*i);
        } else{
        double radians = fillDegree/countInCircles*i * M_PI / (fillDegree/2);
        double newX2 = center2.x() + radius  * cos(radians);
        double newY2 = center2.y() + radius  * sin(radians);
        centersList.append(QPointF(newX2 , newY2));
        listForParking.append(QPointF(newX2 , newY2));
        }
    }
    for (int i = 0; i < 3; ++i) {
        brushList.append(Qt::green);
        brushList.append(Qt::yellow);
        brushList.append(Qt::gray);
        brushList.append(Qt::blue);
        brushList.append(Qt::red);
        brushList.append(Qt::black);
        brushList.append(Qt::cyan);
    }
}

void Scene::paintPie(QPainter *painter, int diameter, QPointF centerEllipse, int angle, const QBrush &brush)
{
    painter->setBrush(brush);
    painter->setPen(Qt::SolidLine);
    painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle, fillDegree/countSections * 16);
}

void Scene::paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color,int angle){
    painter->setBrush(color);
    painter->setPen(Qt::SolidLine);
    painter->drawEllipse(centerEllipse,diameter,diameter);
    qDebug() << "paintEllipse";
    for (int i = 0; i < countSections; ++i) {
        int angleForCenter = (-angle+((fillDegree/countSections)*i)) * 16;
        paintPie(painter, diameter, centerEllipse, angleForCenter,brushList[i]);
    }
}



void Scene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->fillRect(sceneRect(),Qt::white);

    for (int i = 0; i < countCircles; ++i) {
        if(i < 6){
            this->paintEllipse(painter,centersList[i],brushList[i],anglesList[i]);
        }
        else{
            this->paintEllipse(painter,centersList[i],brushList[i],anglesList[i-6]);
        }
    }
}

QPointF Scene::setCenter(int &angle, QGraphicsSceneMouseEvent *event, QPointF center){
    if(press.x() <= event->scenePos().x()){
        qDebug() << "right";
        angle += changeAngleSpeed;
        if (angle >= fillDegree) angle -= fillDegree;
    }
    else{
        qDebug() << "left";
        angle -= changeAngleSpeed;
        if (angle <= -fillDegree) angle += fillDegree;
    }
    double radians = angle * M_PI / (fillDegree/2);
    double newX = center.x() + radius  * cos(radians);
    double newY = center.y() + radius  * sin(radians);
    return QPointF(newX, newY);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    for (int i = 0; i < countInCircles; ++i) {
        //centersActive[i] = this->setCenter(anglesList[i],event, center);
        if(i < 6){
            centersList[i] = this->setCenter(anglesList[i],event, center);
        }
    }
    update();
    qDebug() << "update";
}

void Scene::hitTest(QPointF center, bool &isPress)
{
    if(press.x() >= center.x()-100 &&press.x() <= center.x()+100){
        if(press.y() >= center.y()- 100 &&press.y() <= center.y()+100){
            qDebug() << "check";
            isPress = true;

        }
    }
}

void Scene::landing(QPointF center)
{
    // for (int i = 0; i < countCircles; ++i) {
    //     if(centersList[i].x() >= center.x()-100 &&centersList[i].x() <= center.x()+100){
    //         if(centersList[i].y() >= center.y()- 100 &&centersList[i].y() <= center.y()+100){
    //             centersActive.append(centersList[i]);
    //         }
    //     }
    // }
}

void Scene::parking()
{

    for (int i = 0; i < countCircles; ++i) {
        for (int j = 0; j < countCircles; ++j) {
            if(centersList[i].x() >= listForParking[j].x()-40 &&centersList[i].x() <= listForParking[j].x()+40){
                if(centersList[i].y() >= listForParking[j].y()-40 &&centersList[i].y() <= listForParking[j].y()+40){
                    centersList[i] = listForParking[j];
                    qDebug() << "BOOOOOOOOOOOO" << i;
                }
            }
        }
    }
    update();
    qDebug() << "parking";
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    press = event->scenePos();
    hitTest(center,isPress1);
    hitTest(center2,isPress2);
    if(isPress1){
        this->landing(center);
    }
    if(isPress2){
        this->landing(center2);
    }
    qDebug() << press;

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    isPress1 = false;
    isPress2 = false;
    qDebug() << "mouseReleaseEvent";
    this->parking();
   //update();
}
