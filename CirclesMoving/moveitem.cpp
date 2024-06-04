#include "moveitem.h"
#include <cmath>

MoveItem::~MoveItem()
{

}
void MoveItem::getMoving(QMouseEvent *event)
{
    isPress = true;
    qDebug() << isPress;

}

void MoveItem::getStoping(QMouseEvent *event){
    isPress = false;
    qDebug() << isPress;
}

void MoveItem::moving(QMouseEvent *event){
    //while(isPress){
    if(isPress){
        angle += 10; // Увеличиваем угол (можно изменить шаг угла по вашему усмотрению)
        if (angle >= 360) angle -= 360; // Угол должен оставаться в пределах 0-360 градусов

        // Переводим угол в радианы для использования в математических функциях
        double radians = angle * M_PI / 180;

        // Рассчитываем новые координаты по окружности
        double newX = centerX + radius * cos(radians);
        double newY = centerY + radius * sin(radians);

        // Устанавливаем новые координаты
        this->setPos(newX, newY);
        this->update();
        //QThread::sleep(1);
    }
  //  }
}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawEllipse(-30,-30,60,60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


