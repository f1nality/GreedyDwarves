#include "gamelogic.h"

GameLogic::GameLogic()
{
}

void GameLogic::ProcessEvents()
{
    foreach (GameUnit *unit, gameUnits)
    {
        unit->nextFrame();

        ((MovableUnit *)unit)->move();
    }
}
