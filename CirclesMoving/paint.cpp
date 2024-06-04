#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paint)
{
    ui->setupUi(this);
    setMouseTracking(true);
    // Косметическая подготовка приложения
    this->resize(640,640);          // Устанавливаем размеры окна приложения
    this->setFixedSize(640,640);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(600,600);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
    item = new MoveItem(0);
    item->setPos(0,0);
    QString str = QString(" %1 , %1 ").arg(item->pos().x()).arg(item->pos().y());
    ui->label->setText(str);
    scene->addItem(item);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item,  SLOT(moving(QMouseEvent*)));
    item2 = new MoveItem(50);
    item2->setPos(0,0);
    scene->addItem(item2);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item2, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item2,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item2,  SLOT(moving(QMouseEvent*)));
    item3 = new MoveItem(100);
    item3->setPos(0,0);
    scene->addItem(item3);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item3, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item3,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item3,  SLOT(moving(QMouseEvent*)));
    item3 = new MoveItem(150);
    item3->setPos(0,0);
    scene->addItem(item3);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item3, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item3,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item3,  SLOT(moving(QMouseEvent*)));
    item3 = new MoveItem(200);
    item3->setPos(0,0);
    scene->addItem(item3);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item3, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item3,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item3,  SLOT(moving(QMouseEvent*)));
    item4 = new MoveItem(250);
    item4->setPos(0,0);
    scene->addItem(item4);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item4, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item4,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item4,  SLOT(moving(QMouseEvent*)));
    item5 = new MoveItem(300);
    item5->setPos(0,0);
    scene->addItem(item5);   // Добавляем элемент на графическую сцену
    connect(this, SIGNAL(isMoving(QMouseEvent*)), item5, SLOT(getMoving(QMouseEvent*)));
    connect(this, SIGNAL(isStoping(QMouseEvent*)), item5,  SLOT(getStoping(QMouseEvent*)));
    connect(this,  SIGNAL(move(QMouseEvent*)), item5,  SLOT(moving(QMouseEvent*)));
}

Paint::~Paint()
{
    delete ui;
}

void Paint::mousePressEvent(QMouseEvent *event){
    emit isMoving(event);
    qDebug() << "mousePressEvent";
}

void Paint::mouseReleaseEvent(QMouseEvent *event){
    emit isStoping(event);
    qDebug() << "mouseReleaseEvent";
}

void Paint::mouseMoveEvent(QMouseEvent *event){
    emit move(event);
    qDebug() << "mouseMoveEvent";
}


void Paint::on_pushButton_clicked()
{
    // MoveItem *item = new MoveItem(0);        // Создаём графический элемента
    // item->setPos(0,0);
    // QString str = QString(" %1 , %1 ").arg(item->pos().x()).arg(item->pos().y());
    // ui->label->setText(str);
    // scene->addItem(item);   // Добавляем элемент на графическую сцену
    // MoveItem *item2 = new MoveItem(50);
    // item2->setPos(20,20);
    // QString str2 = QString(" %1 , %1 ").arg(item2->pos().x()).arg(item2->pos().y());
    // ui->label->setText(str2);
    // scene->addItem(item2);
    // MoveItem *item3 = new MoveItem(100);
    // item3->setPos(40,40);
    // QString str3 = QString(" %1 , %1 ").arg(item3->pos().x()).arg(item3->pos().y());
    // ui->label->setText(str3);
    // scene->addItem(item3);
    // MoveItem *item4 = new MoveItem(150);
    // item4->setPos(80,80);
    // QString str4 = QString(" %1 , %1 ").arg(item4->pos().x()).arg(item4->pos().y());
    // ui->label->setText(str4);
    // scene->addItem(item4);
    // MoveItem *item5 = new MoveItem(200);
    // item5->setPos(120,120);
    // QString str5 = QString(" %1 , %1 ").arg(item5->pos().x()).arg(item5->pos().y());
    // ui->label->setText(str5);
    // scene->addItem(item5);
    // MoveItem *item6 = new MoveItem(250);
    // item6->setPos(160,160);
    // QString str6 = QString(" %1 , %1 ").arg(item6->pos().x()).arg(item6->pos().y());
    // ui->label->setText(str6);
    // scene->addItem(item6);
    // MoveItem *item7 = new MoveItem(300);
    // item7->setPos(200,200);
    // QString str7 = QString(" %1 , %1 ").arg(item7->pos().x()).arg(item7->pos().y());
    // ui->label->setText(str7);
    // scene->addItem(item7);
     connect(item, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item2, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item3, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item4, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item5, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item6, &MoveItem::moving, item7, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item2, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item3, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item4, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item5, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item6, &MoveItem::getMoving);
    // connect(item7, &MoveItem::moving, item7, &MoveItem::getMoving);
}

