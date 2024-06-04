#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QGraphicsScene>
#include <QDebug>

#include <moveitem.h>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT


public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();
    Ui::Paint *ui;
    MoveItem* createItem(MoveItem *item,int angle);

signals:
    void isMoving(QMouseEvent *event);
    void isStoping(QMouseEvent *event);
    void move(QMouseEvent *event);

private:

    QGraphicsScene *scene;
    MoveItem *item;
    MoveItem *item2;
    MoveItem *item3;
    MoveItem *item4;
    MoveItem *item5;
    MoveItem *item6;
    MoveItem *item7;

private slots:
    void on_pushButton_clicked();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // PAINT_H
