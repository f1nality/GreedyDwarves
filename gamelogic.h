#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include <QTimer>
#include "gameunit.h"
#include "movableunit.h"
#include "swordsman.h"
#include "baseunit.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic();
    QList<GameUnit *> getGameUnits();
    void ProcessEvents();

private:
    void coolDown();
    void buyUnit();
    void mine();
    void buyMiner();
    BaseUnit *base;
    QTimer gameTimer;
    QList<GameUnit *> gameUnits;
    int cooldown;
public slots:
    void unitOfTimeElapsed();
signals:
    void GameUpdated();
};

#endif // GAMELOGIC_H
