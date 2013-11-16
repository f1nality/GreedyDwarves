#include "gamelogic.h"
#include "baseunit.h"
#include "swordsman.h"
#include "bossunit.h"
#include "warriorunit.h"
#include "minerunit.h"
#include <QDebug>
GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    base = new BaseUnit(10, -10);
    boss = new BossUnit(400,-20);

    gameUnits.append(base);
    gameUnits.append(boss);

    UICooldownButton *swordsManButton = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32), SwordsMan::cooldown);
    UICooldownButton *minerButton = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32), MinerUnit::cooldown);

    QObject::connect(swordsManButton, SIGNAL(pressed()), this, SLOT(buyUnit()));
    QObject::connect(minerButton, SIGNAL(pressed()), this, SLOT(buyMiner()));

    addCooldownButton(swordsManButton);
    addCooldownButton(minerButton);
}

QList<GameUnit *> GameLogic::getGameUnits()
{
    return gameUnits;
}

QList<UICooldownButton *> GameLogic::getCooldownButtons()
{
    return cooldownButtons;
}

int GameLogic::getGold()
{
    return base->getGold();
}

void GameLogic::ProcessEvents()
{
    if (!playerAWarriorUnits.isEmpty() && !playerBWarriorUnits.isEmpty())
    {
        WarriorUnit *frontPlayerAUnit = playerAWarriorUnits.front();
        WarriorUnit *frontPlayerBUnit = playerBWarriorUnits.front();

        if (frontPlayerBUnit->getX() - (frontPlayerAUnit->getX() + frontPlayerAUnit->getWidth()) < 2)
        {
            frontPlayerAUnit->attack(frontPlayerBUnit);
            frontPlayerBUnit->attack(frontPlayerAUnit);

            if (frontPlayerAUnit->getHealthPoints() < 0)
            {
                gameUnits.removeOne(frontPlayerAUnit);
                playerAWarriorUnits.removeOne(frontPlayerAUnit);
            }

            if (frontPlayerBUnit->getHealthPoints() < 0)
            {
                gameUnits.removeOne(frontPlayerBUnit);
                playerBWarriorUnits.removeOne(frontPlayerBUnit);
            }
        }
    }

    WarriorUnit *nextUnit = NULL;

    foreach (WarriorUnit *unit, playerAWarriorUnits)
    {
        if (nextUnit == NULL || unit->getX() + unit->getWidth() < nextUnit->getX())
        {
            unit->moveIfNeeded();
        }

        unit->nextFrame();

        nextUnit = unit;
    }

    nextUnit = NULL;

    foreach (WarriorUnit *unit, playerBWarriorUnits)
    {
        if (nextUnit == NULL || unit->getX() - unit->getWidth() > nextUnit->getX())
        {
            unit->moveIfNeeded();
        }

        unit->nextFrame();

        nextUnit = unit;
    }

    if (timeElapsedSinceLastMine < timePerMine)
    {
        ++timeElapsedSinceLastMine;
    }
    else
    {
        mine();
    }

    if (timeElapsedSinceLastSpawn < timePerSpawn)
    {
        ++timeElapsedSinceLastSpawn;
    }
    else
    {
        SwordsMan *enemy = new SwordsMan(400, 0);

        enemy->setDirectionForward(false);

        gameUnits.append(enemy);
        playerBWarriorUnits.append(enemy);

        timeElapsedSinceLastSpawn = 0;
    }

    foreach (UICooldownButton *button, cooldownButtons)
    {
        button->updateCooldownElapsedIfNeeded();
    }

    emit GameUpdated();
}

void GameLogic::mine()
{
    base->setGold(base->getGold() + base->getMiners());
    timeElapsedSinceLastMine = 0;
}

void GameLogic::addCooldownButton(UICooldownButton *button)
{
    cooldownButtons.append(button);
}

void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}

void GameLogic::buyUnit()
{
    if (base->getGold() < SwordsMan::cost)
    {
        return;
    }

    base->setGold(base->getGold() - SwordsMan::cost);

    SwordsMan *swordsMan = new SwordsMan(100, 0);

    gameUnits.append(swordsMan);
    playerAWarriorUnits.append(swordsMan);

    UICooldownButton *button = (UICooldownButton *)sender();

    button->resetCooldownElapsed();
}

void GameLogic::buyMiner()
{
    if (base->getGold() < base->getMinerCost())
    {
        return;
    }

    base->buyMiner();
    gameUnits.append(new MinerUnit(20 + base->getMiners() * 60 , 20));

    UICooldownButton *button = (UICooldownButton *)sender();

    button->resetCooldownElapsed();
}
