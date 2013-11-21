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
#include "uicooldownbutton.h"
#include "minerunit.h"
#include "bull.h"
#include "skeletonarcher.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic();
    QList<GameUnit *> getGameUnits();
    QList<UICooldownButton *> getCooldownButtons();
    int getGold();
    void ProcessEvents();
private:
    BaseUnit *base;
    BossUnit *boss;
    MinerUnit *miner;
    QTimer gameTimer;
    QList<GameUnit *> gameUnits;
    QList<WarriorUnit *> playerAWarriorUnits;
    QList<WarriorUnit *> playerBWarriorUnits;
    QList<UICooldownButton *> cooldownButtons;
    size_t timeElapsedSinceLastMine;
    static const size_t timePerMine = 10;
    size_t timeElapsedSinceLastSpawn;
    static const size_t timePerSpawn = 200;
    void mine();
    void addCooldownButton(UICooldownButton *button);
    void fight();
    void move();
    void bossTurn();
public slots:
    void unitOfTimeElapsed();
private slots:
    void buyUnit();
    void buyMiner();
signals:
    void GameUpdated();
};

#endif // GAMELOGIC_H
