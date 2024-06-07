#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QPainter>
#include <QDebug>

class Scene : public QGraphicsScene {

    Q_OBJECT
private:
    QPointF center;
    QPointF center2;
    QPointF center3;
    QPointF center4;
    QPointF center5;
    QPointF press;
    int angle = 0;
    int angle2 = 72;
    int angle3 = 144;
    int angle4 = 216;
    int angle5 = 288;
    QPointF setCenter(int &angle, QGraphicsSceneMouseEvent *event);
    void paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color, int diameter = 30);
    void paintCenter(QPainter *painter, QPointF centerEllipse, int diameter, int angle);
public:

    explicit Scene(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
