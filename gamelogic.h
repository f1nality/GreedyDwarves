#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include "gameunit.h"
#include "movableunit.h"

class GameLogic
{
public:
    GameLogic();
    QList<GameUnit *> gameUnits;
    void ProcessEvents();
};

#endif // GAMELOGIC_H
