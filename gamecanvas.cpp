#include "gamecanvas.h"
#include "gamelogic.h"
#include "swordsman.h"

GameLogic *gameLogic = new GameLogic();
GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    position = 0;

    gameLogic->gameUnits.append(new SwordsMan(40, 110));
}

void GameCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 0, QImage(":/graphics/background.png"), 0, 0, -1, -1, 0);

    //painter.setPen(Qt::darkGreen);
    //painter.drawRect(0, 0, 320, 240);

    //painter.drawImage(position, 0, QImage(":/graphics/img.png"), tt * 32, 0, 32, 32, 0);

    foreach (GameUnit *unit, gameLogic->gameUnits)
    {
        painter.drawImage((int)unit->getX(), (int)unit->getY(), *unit->getImage(), unit->getCurrentFrame() * 32, 0, unit->getWidth(), unit->getHeight(), 0);
    }

    gameLogic->ProcessEvents();
}
