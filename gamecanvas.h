#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "gamelogic.h"

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
private:
    GameLogic *gameLogic;
public slots:
    void onGameUpdated();
};

#endif // GAMECANVAS_H
