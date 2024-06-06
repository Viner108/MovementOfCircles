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
    QPointF press;
    int radius;
    int angle = 0;
    int angle2 = 90;
    int angle3 = 180;
    int angle4 = 270;
    QPointF setCenter(int &angle, QGraphicsSceneMouseEvent *event);
    void paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color);
public:

    explicit Scene(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
