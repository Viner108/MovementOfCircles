#include "scene.h"

void Scene::createCircles(int i, int k)
{
    int j = 0;
    switch (k) {
    case 2:
    case 3:
        j = 1;
        break;
    case 4:
    case 5:
        j = 2;
        break;
    case 6:
    case 7:
        j = 3;
        break;
    }
    double radians = fillDegree/countInCircles*(i - (countInCircles * k) + j)  * M_PI / (fillDegree/2);
    double newX = centersList[k].x() + radius  * cos(radians);
    double newY = centersList[k].y() + radius  * sin(radians);
    circlesMap.insert(i,QPointF(newX , newY));
    mapForParking.insert(i,QPointF(newX , newY));
    anglesList.append(fillDegree/countInCircles*(i - (countInCircles * k)));

}

void Scene::fillColorList()
{
    for (int i = 0; i < 50; ++i) {
        brushList.append(Qt::green);
        // brushList.append(Qt::yellow);
        // brushList.append(Qt::gray);
        // brushList.append(Qt::blue);
        // brushList.append(Qt::red);
        // brushList.append(Qt::black);
        // brushList.append(Qt::cyan);
    }
}

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0,0,sizeScene,sizeScene);
    centersList.append(center);
    centersList.append(center2);
    centersList.append(center3);
    centersList.append(center4);
    centersList.append(center5);
    centersList.append(center6);
    centersList.append(center7);
    centersList.append(center8);
    int k = 0;
    for (int i = 0; i < countCircles; ++i) {
        if(i < 6){
            k = 0;
        }
        else if(i >= 6 && i < 10){
            k = 1;
        }
        else if(i >= 10 && i < 13){
            k = 2;
        }
        else if(i >= 13 && i < 16){
            k = 3;
        }
        else if(i >= 16 && i < 19){
            k = 4;
        }
        else if(i >= 19 && i < 22){
            k = 5;
        }
        else if(i >= 22 && i < 25){
            k = 6;
        }
        else if(i >= 25 && i < 28){
            k = 7;
        }
        createCircles(i,k);
        qDebug() << k;
    }
    fillColorList();
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
        this->paintEllipse(painter,circlesMap[i],brushList[i],anglesList[i]);
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
    for (int i = 0; i < circlesActive.size(); ++i) {
        circlesMap[circlesActive[i]] = this->setCenter(anglesList[i],event, currentCenter);
        // if(i < 6){
        // }
    }
    update();

    qDebug() << "update";
}

bool Scene::hitTest(QPointF center)
{
    if(press.x() >= center.x()-80 &&press.x() <= center.x()+80){
        if(press.y() >= center.y()- 80 &&press.y() <= center.y()+80){
            qDebug() << "check";
            return true;

        }
    }
    return false;
}

void Scene::landing(QPointF center)
{
    circlesActive.clear();
    for (int i = 0; i < countCircles; ++i) {
        if(circlesMap[i].x() >= center.x()-120 &&circlesMap[i].x() <= center.x()+120){
            if(circlesMap[i].y() >= center.y()- 120 &&circlesMap[i].y() <= center.y()+120){
                circlesActive.append(i);
                qDebug() << "BOOOOOOOOOOOO" << i;
            }
        }
    }
    qDebug() << "landing";
}

void Scene::parking()
{

    for (int i = 0; i < countCircles; ++i) {
        for (int j = 0; j < countCircles; ++j) {
            if(circlesMap[i].x() >= mapForParking[j].x()-35 &&circlesMap[i].x() <= mapForParking[j].x()+35){
                if(circlesMap[i].y() >= mapForParking[j].y()-35 &&circlesMap[i].y() <= mapForParking[j].y()+35){
                    circlesMap[i] = mapForParking[j];
                }
            }
        }
    }
    update();
    qDebug() << "parking";
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    press = event->scenePos();
    isPress1 = hitTest(center);
    isPress2 = hitTest(center2);
    isPress3 = hitTest(center3);
    isPress4 = hitTest(center4);
    isPress5 = hitTest(center5);
    isPress6 = hitTest(center6);
    isPress7 = hitTest(center7);
    isPress8 = hitTest(center8);
    if(isPress1){
        currentCenter = center;
    }else if(isPress2){
        currentCenter = center2;
    }else if(isPress3){
        currentCenter = center3;
    }else if(isPress4){
        currentCenter = center4;
    }else if(isPress5){
        currentCenter = center5;
    }else if(isPress6){
        currentCenter = center6;
    }else if(isPress7){
        currentCenter = center7;
    }else if(isPress8){
        currentCenter = center8;
    }
    this->landing(currentCenter);
    qDebug() << press;
    qDebug() << "mousePressEvent";

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    isPress1 = false;
    isPress2 = false;
    isPress3 = false;
    isPress4 = false;
    isPress5 = false;
    isPress6 = false;
    isPress7 = false;
    isPress8 = false;
    qDebug() << "mouseReleaseEvent";
    this->parking();
}
