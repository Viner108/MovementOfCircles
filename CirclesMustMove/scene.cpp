#include "scene.h"

void Scene::createCircles(int i)
{
    double radians = fillDegree/countInCircles*i * M_PI / (fillDegree/2);
    double newX = center.x() + radius  * cos(radians);
    double newY = center.y() + radius  * sin(radians);
    circlesMap.insert(i,QPointF(newX , newY));
    mapForParking.insert(i,QPointF(newX , newY));
    anglesList.append(fillDegree/countInCircles*i);
}

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0,0,sizeScene,sizeScene);
    for (int i = 0; i < countCircles; ++i) {
        if(i < countInCircles){
        createCircles(i);
        } else{
        double radians = fillDegree/countInCircles*i * M_PI / (fillDegree/2);
        double newX2 = center2.x() + radius  * cos(radians);
        double newY2 = center2.y() + radius  * sin(radians);
        circlesMap.insert(i,QPointF(newX2 , newY2));
        mapForParking.insert(i,QPointF(newX2 , newY2));
        anglesList.append(fillDegree/countInCircles*(i-countInCircles));
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
            this->paintEllipse(painter,circlesMap[i],brushList[i],anglesList[i]);
        }
        else{
            this->paintEllipse(painter,circlesMap[i],brushList[i],anglesList[i-6]);
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
    if(press.x() >= center.x()-100 &&press.x() <= center.x()+100){
        if(press.y() >= center.y()- 100 &&press.y() <= center.y()+100){
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
            if(circlesMap[i].x() >= mapForParking[j].x()-40 &&circlesMap[i].x() <= mapForParking[j].x()+40){
                if(circlesMap[i].y() >= mapForParking[j].y()-40 &&circlesMap[i].y() <= mapForParking[j].y()+40){
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
    if(isPress1){
        currentCenter = center;
    }else if(isPress2){
        currentCenter = center2;
    }
    this->landing(currentCenter);
    qDebug() << press;
    qDebug() << "mousePressEvent";

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    isPress1 = false;
    isPress2 = false;
    qDebug() << "mouseReleaseEvent";
    this->parking();
}
