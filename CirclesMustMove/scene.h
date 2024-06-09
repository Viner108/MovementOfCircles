#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QPainter>
#include <QDebug>
#include <QList>
#include <QBrush>
#include <QMap>
#include <QtMath>

class Scene : public QGraphicsScene {

    Q_OBJECT
private:
    QMap<int , QPointF> circlesMap;

    QList<QPointF> mapForParking;

    QList<int> originAngles;

    QList<int > circlesActive;

    QList<QBrush> brushList;

    int sizeScene = 400;

    bool isPress1 = false;

    bool isPress2 = false;

    bool isPress3 = false;

    bool isPress4 = false;

    bool isPress5 = false;

    bool isPress6 = false;

    bool isPress7 = false;

    bool isPress8 = false;

    int countCenters = 8;

    int countCircles = 28;

    int countInCircles = 6;

    int countSections = 4;

    QPointF center = QPointF(100,100);

    QPointF center2 = QPointF(100,235);

    QPointF center3 = QPointF(225,165);

    QPointF center4 = QPointF(-25,165);

    QPointF center5 = QPointF(225,300);

    QPointF center6 = QPointF(-25,35);

    QPointF center7 = QPointF(-25,300);

    QPointF center8 = QPointF(225,35);

    QList<QPointF> centersList;

    QPointF currentCenter;

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

    bool hitTest(QPointF center);

    int chooseAngel(QPointF center, QPointF circle);

    void chooseActiveCircles(QPointF center);

    void parking();

    void createCircles(int i, int k);

    void fillColorList();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
