#include "circle.h"

Circle::Circle(QPointF center, QBrush brush, int angle) :
    center(center),
    brush(brush),
    angle(angle)
{}

void Circle::paintPie(QPainter *painter, int diameter, QPointF centerEllipse, int angle, const QBrush &brush)
{
    // painter->setBrush(brush);
    // painter->setPen(Qt::SolidLine);
    // painter->drawPie(centerEllipse.x()-(diameter/2),centerEllipse.y()-(diameter/2), diameter, diameter, angle, fillDegree/countSections * 16);
}

void Circle::paint(QPainter *painter, QPointF centerEllipse, const QBrush &color,int angle){
    // painter->setBrush(color);
    // painter->setPen(Qt::SolidLine);
    // painter->drawEllipse(centerEllipse,diameter,diameter);
    // for (int i = 0; i < countSections; ++i) {
    //     int angleForCenter = (-angle+((fillDegree/countSections)*i)) * 16;
    //     paintPie(painter, diameter, centerEllipse, angleForCenter,brushList[i]);
    // }
}
