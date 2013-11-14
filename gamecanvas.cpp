#include "gamecanvas.h"
#include "gamelogic.h"
#include "swordsman.h"

GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    ROAD_Y = 195;
}

void GameCanvas::setGameLogic(GameLogic *gameLogic)
{
    this->gameLogic = gameLogic;
}

void GameCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 0, QImage(":/graphics/background.png"), 0, 0, -1, -1, 0);

    foreach (GameUnit *unit, gameLogic->getGameUnits())
    {
        painter.drawImage((int)unit->getX(), ROAD_Y - unit->getHeight() - (int)unit->getY(), *unit->getImage(), unit->getCurrentFrame() * 32, 0, unit->getWidth(), unit->getHeight(), 0);
    }
}

void GameCanvas::onGameUpdated()
{
    repaint();
}

