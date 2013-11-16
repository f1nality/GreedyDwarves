#include "gamelogic.h"
#include "baseunit.h"
#include "swordsman.h"
#include "bossunit.h"
#include "warriorunit.h"
#include "minerunit.h"

GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    base = new BaseUnit(10, -10);
    boss = new BossUnit(400,-20);

    this->gameUnits.append(base);
    this->gameUnits.append(boss);

    UICooldownButton *swordsManButton = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32), 30);
    UICooldownButton *minerButton = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32), 100);

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
    foreach (GameUnit *unit, gameUnits)
    {
        MovableUnit *movableUnit = dynamic_cast<MovableUnit *>(unit);

        unit->nextFrame();

        if (movableUnit)
        {
            WarriorUnit *warriorUnit = dynamic_cast<WarriorUnit *>(unit);

            if (warriorUnit)
            {
                if (boss->getX() - warriorUnit->getX() < 2 && boss->getHP() > 0)
                {
                    warriorUnit->startFight();
                }

                if (!warriorUnit->getState())
                {
                    warriorUnit->move();
                }
                else
                {
                    boss->setHP(boss->getHP() - warriorUnit->getDamage());

                    if (boss->getHP() <= 0)
                    {
                        this->gameUnits.removeOne(boss);
                        //delete boss;
                        warriorUnit->stopFight();
                    }
                }
            }
            else
            {
                movableUnit->move();
            }
        }

        BossUnit *bossUnit = dynamic_cast<BossUnit *>(unit);

        if (bossUnit)
        {

        }
    }

    if (timeElapsedSinceLastMine < timePerMine)
    {
        ++timeElapsedSinceLastMine;
    }
    else
    {
        mine();
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
    gameUnits.append(new SwordsMan(100, 0));

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
