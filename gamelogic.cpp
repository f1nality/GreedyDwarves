#include "gamelogic.h"

GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    this->gameUnits.append(new SwordsMan());
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
