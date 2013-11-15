#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include <QTimer>
#include "gameunit.h"
#include "movableunit.h"
#include "swordsman.h"
#include "baseunit.h"
#include "bossunit.h"
#include "warriorunit.h"


class GameLogic : public QObject
{
    Q_OBJECT
public:
    void buy();
    GameLogic();
    QList<GameUnit *> getGameUnits();
    int getGold();
    void ProcessEvents();
private:
    void decCooldown();
    void buyUnit();
    void mine();
    void buyMiner();
    BaseUnit *base;
    BossUnit *boss;
    QTimer gameTimer;
    QList<GameUnit *> gameUnits;
    int cooldown;
public slots:
    void unitOfTimeElapsed();
signals:
    void GameUpdated();
};

#endif // GAMELOGIC_H
