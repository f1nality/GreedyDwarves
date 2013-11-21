#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QList>
#include <QSize>
#include "uicooldownbutton.h"
#include "gamelogic.h"
#include "gamelogic.h"
#include "swordsman.h"

class GameCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit GameCanvas(QWidget *parent = 0);
    void setGameLogic(GameLogic *gameLogic);
protected:
    void paintEvent(QPaintEvent *);
private:
    int ROAD_Y;
    GameLogic *gameLogic;
    int mousePressedX;
    int mousePressedY;
    void addCooldownButton(UICooldownButton *button);
    int getCooldownButtonX(size_t index);
    int getCooldownButtonY(size_t index);
    void mousePressEvent(QMouseEvent *mouseEvent);
    void mouseReleaseEvent(QMouseEvent *mouseEvent);
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    bool isPointInArea(int x, int y, int rect_x, int rect_y, QSize rect_size);
    void drawGameUnits(QPainter &painter);
    void drawHealthBar(QPainter &painter, WarriorUnit *unit);
    void drawMinersCount(QPainter &painter, MinerUnit *unit);
    void drawCooldownButtons(QPainter &painter);
    void drawGold(QPainter &painter);
public slots:
    void onGameUpdated();
};

#endif // GAMECANVAS_H
