#include "gamelogic.h"
#include "baseunit.h"
GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    this->gameUnits.append(new BaseUnit(10, -10));
    this->gameUnits.append(new SwordsMan(100, 0));
}

QList<GameUnit *> GameLogic::getGameUnits()
{
    return this->gameUnits;
}

void GameLogic::ProcessEvents()
{
    foreach (GameUnit *unit, gameUnits)
    {
        unit->nextFrame();

        ((MovableUnit *)unit)->move();
    }

    emit GameUpdated();
}

void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}
