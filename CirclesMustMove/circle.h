#ifndef CIRCLE_H
#define CIRCLE_H
#include <QPointF>
#include <QPainter>
#include <QDebug>
#include <QList>
#include <QBrush>

class Circle
{
public:
    Circle(QPointF center, QBrush brush, int angle);
    void paint(QPainter *painter, QPointF centerEllipse, const QBrush &color,int angle);
    void paintPie(QPainter *painter, int diameter, QPointF centerEllipse, int angle, const QBrush &brush);
private:
    QPointF center;
    QBrush brush;
    int angle;

};

#endif // CIRCLE_H
