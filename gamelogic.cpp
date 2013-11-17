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

    UICooldownButton *swordsManButton = new UICooldownButton(QImage(":/graphics/swordsman.png"), QSize(32, 32), SwordsMan::cooldown);
    UICooldownButton *minerButton = new UICooldownButton(QImage(":/graphics/miner.png"), QSize(40, 39), MinerUnit::cooldown);

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

                BaseUnit *baseUnit = dynamic_cast<BaseUnit *>(frontPlayerAUnit);

                if (baseUnit)
                {
                    gameUnits.removeOne(miner);

                    base = NULL;
                    miner = NULL;
                }
            }

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
    }

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
        if (nextUnit == NULL || unit->getX() - unit->getWidth() > nextUnit->getX())
        {
            unit->moveIfNeeded();
        }

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

    if (boss)
    {
        if (timeElapsedSinceLastSpawn < timePerSpawn)
        {
            ++timeElapsedSinceLastSpawn;
        }
        else
        {
            Bull *enemy = new Bull(boss->getX() - 58, 0);

            enemy->setDirectionForward(false);

            gameUnits.append(enemy);
            playerBWarriorUnits.insert(playerBWarriorUnits.length() - 1, enemy);

            timeElapsedSinceLastSpawn = 0;
        }
    }

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
    playerAWarriorUnits.insert(playerAWarriorUnits.length() - 1, swordsMan);

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

    UICooldownButton *button = (UICooldownButton *)sender();

    button->resetCooldownElapsed();
}
