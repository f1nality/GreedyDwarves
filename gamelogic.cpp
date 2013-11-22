#include "gamelogic.h"
#include <QDebug>
GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    base = new BaseUnit(10, -10);
    boss = new BossUnit(520, -10);
    miner = new MinerUnit(110 , 28, base);

    gameUnits.append(miner);

    gameUnits.append(base);
    playerAWarriorUnits.append(base);
    gameUnits.append(boss);
    playerBWarriorUnits.append(boss);

    UICooldownButton *swordsManButton = new UICooldownButton("SwordsMan", QImage(":/graphics/swordsman.png"), QSize(32, 32), SwordsMan::cooldown);
    UICooldownButton *axeManButton = new UICooldownButton("AxeMan", QImage(":/graphics/axeman.png"), QSize(32, 32), AxeMan::cooldown);
    UICooldownButton *minerButton = new UICooldownButton("MinerUnit", QImage(":/graphics/miner.png"), QSize(40, 39), MinerUnit::cooldown);

    QObject::connect(swordsManButton, SIGNAL(pressed()), this, SLOT(buyUnit()));
    QObject::connect(axeManButton, SIGNAL(pressed()), this, SLOT(buyUnit()));
    QObject::connect(minerButton, SIGNAL(pressed()), this, SLOT(buyMiner()));

    addCooldownButton(swordsManButton);
    addCooldownButton(axeManButton);
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
    fight();

    move();
    mine();

    enemyTurn();

    foreach (GameUnit *unit, gameUnits)
    {
        unit->nextFrame();
    }

    foreach (UICooldownButton *button, cooldownButtons)
    {
        button->updateCooldownElapsedIfNeeded();
    }

    emit GameUpdated();
}

void GameLogic::mine()
{
    if (timeElapsedSinceLastMine < timePerMine)
    {
        ++timeElapsedSinceLastMine;
    }
    else
    {
        base->setGold(base->getGold() + base->getMiners());
        timeElapsedSinceLastMine = 0;
    }
}

void GameLogic::addCooldownButton(UICooldownButton *button)
{
    cooldownButtons.append(button);
}

void GameLogic::fight()
{
    if (!playerAWarriorUnits.isEmpty() && !playerBWarriorUnits.isEmpty())
    {
        WarriorUnit *frontPlayerAUnit = playerAWarriorUnits.front();
        WarriorUnit *frontPlayerBUnit = playerBWarriorUnits.front();
        foreach(WarriorUnit *PlayerAUnit, playerAWarriorUnits) {
            if (frontPlayerBUnit->getX() - (PlayerAUnit->getX() + PlayerAUnit->getWidth()) < PlayerAUnit->getRange())
            {
                PlayerAUnit->attack(frontPlayerBUnit);

                if (frontPlayerBUnit->getHealthPoints() < 0)
                {
                    gameUnits.removeOne(frontPlayerBUnit);
                    playerBWarriorUnits.removeOne(frontPlayerBUnit);

                    BossUnit *bossUnit = dynamic_cast<BossUnit *>(frontPlayerBUnit);

                    if (bossUnit)
                    {
                        boss = NULL;
                    }
                }
            }
            else {
                PlayerAUnit->setAttacking(false);
            }
        }
        foreach(WarriorUnit *PlayerBUnit, playerBWarriorUnits){
            if (PlayerBUnit->getX() - (frontPlayerAUnit->getX() + frontPlayerAUnit->getWidth()) < PlayerBUnit->getRange())
            {
                PlayerBUnit->attack(frontPlayerAUnit);

                if (frontPlayerAUnit->getHealthPoints() < 0)
                {
                    gameUnits.removeOne(frontPlayerAUnit);
                    playerAWarriorUnits.removeOne(frontPlayerAUnit);

                    BaseUnit *baseUnit = dynamic_cast<BaseUnit *>(frontPlayerAUnit);

                    if (baseUnit)
                    {
                        gameUnits.removeOne(miner);

                        base = NULL;
                        miner = NULL;
                    }
                }
            } else {
                PlayerBUnit->setAttacking(false);
            }
        }
    }

}

void GameLogic::move()
{
    WarriorUnit *nextUnit = NULL;

    foreach (WarriorUnit *unit, playerAWarriorUnits)
    {
        if (nextUnit == NULL || unit->getX() + unit->getWidth() < nextUnit->getX())
        {
            unit->moveIfNeeded();
        }

        nextUnit = unit;
    }

    nextUnit = NULL;

    foreach (WarriorUnit *unit, playerBWarriorUnits)
    {
        if (nextUnit == NULL || unit->getX()  > nextUnit->getX() + nextUnit->getWidth())
        {
            unit->moveIfNeeded();
        }

        nextUnit = unit;
    }

}

void GameLogic::enemyTurn()
{
    if (boss)
    {
        if (timeElapsedSinceLastSpawn < timePerSpawn)
        {
            ++timeElapsedSinceLastSpawn;
        }
        else
        {
            WarriorUnit *enemy;
            if(timeElapsedSinceLastSpawn%100 !=0) {
               enemy = new Bull(boss->getX() - 58, 0);
            } else {
                enemy = new SkeletonArcher(boss->getX() - 58, 0);
            }
            enemy->setDirectionForward(false);
            gameUnits.append(enemy);            
            playerBWarriorUnits.insert(playerBWarriorUnits.length() - 1, enemy);

            timeElapsedSinceLastSpawn = 0;
        }

    }
}

void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}

void GameLogic::buyUnit()
{
    WarriorUnit *unit = NULL;
    UICooldownButton *button = (UICooldownButton *)sender();

    if (button->getType() == "SwordsMan" && base->getGold() >= SwordsMan::cost)
    {
        base->setGold(base->getGold() - SwordsMan::cost);
        unit = new SwordsMan(100, 0);
    }
    else if (button->getType() == "AxeMan" && base->getGold() >= AxeMan::cost)
    {
        base->setGold(base->getGold() - AxeMan::cost);
        unit = new AxeMan(100, 0);
    }

    if (unit != NULL)
    {
        gameUnits.append(unit);
        playerAWarriorUnits.insert(playerAWarriorUnits.length() - 1, unit);

        button->resetCooldownElapsed();
    }
}

void GameLogic::buyMiner()
{
    if (base->getGold() < base->getMinerCost())
    {
        return;
    }

    base->buyMiner();

    UICooldownButton *button = (UICooldownButton *)sender();

    button->resetCooldownElapsed();
}
