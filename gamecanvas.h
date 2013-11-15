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
    QList<UICooldownButton *> cooldownButtons;
    int mousePressedX;
    int mousePressedY;
    void addCooldownButton(UICooldownButton *button);
    void mousePressEvent(QMouseEvent *mouseEvent);
    void mouseReleaseEvent(QMouseEvent *mouseEvent);
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    bool isPointInArea(int x, int y, int rect_x, int rect_y, QSize rect_size);
public slots:
    void onGameUpdated();
private slots:
    void onCooldownButtonPressed();
};

#endif // GAMECANVAS_H
