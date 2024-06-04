#ifndef MOVEITEM_H
#define MOVEITEM_H
#include <QWidget>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>


#include <QCursor>
#include <QThread>


class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    MoveItem(double angle): angle(angle), radius(100){
        initialX = this->pos().x();
        initialY = this->pos().y();
        centerX = initialX + 150;
        centerY = initialY + 200;
    };
    ~MoveItem();

signals:

private:
    bool isPress = false;
    double initialX, initialY; // Начальные координаты объекта
    double centerX, centerY; // Центр окружности
    double angle; // Текущий угол в градусах
    double radius; // Радиус окружности
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
     void getMoving(QMouseEvent *event);
     void getStoping(QMouseEvent *event);
     void moving(QMouseEvent *event);

};

#endif // MOVEITEM_H
