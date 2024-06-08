#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QPainter>
#include <QDebug>
#include <QList>
#include <QBrush>

class Scene : public QGraphicsScene {

    Q_OBJECT
private:
    QList<QPointF> centersList;

    QList<QPointF> centersActive;

    QList<QBrush> brushList;

    int sizeScene = 400;

    bool isPress1 = false;

    bool isPress2 = false;

    int countCircles = 10;

    int countInCircles = 6;

    int countSections = 4;

    QPointF center = QPointF(100,100);

    QPointF center2 = QPointF(100,230);

    int radius = 80;

    int diameter = 30;

    int fillDegree = 360;

    int changeAngleSpeed = 2;

    QPointF press;

    QList<int> anglesList;

    QPointF setCenter(int &angle, QGraphicsSceneMouseEvent *event, QPointF center);

    void paintEllipse(QPainter *painter, QPointF centerEllipse, const QBrush &color, int angle);

    void paintCenter(QPainter *painter, QPointF centerEllipse, int diameter, int angle);
public:

    explicit Scene(QObject *parent = nullptr);

    void paintCircles(QPainter *painter);

    void paintPie(QPainter *painter, int diameter, QPointF centerEllipse, int angle, const QBrush &brush);

    void intersectionCheck();

    void hitTest(QPointF center, bool &isPress);

    void landing(QPointF center);

    void parking();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
