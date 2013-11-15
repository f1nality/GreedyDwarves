#include "gamelogic.h"
#include "baseunit.h"
#include "swordsman.h"
#include "bossunit.h"
#include "warriorunit.h"
#include "minerunit.h"

void GameLogic::buyU()
{
    buyUnit();
}

void GameLogic::buyM()
{
    buyMiner();
}

GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    cooldown = 0;

    base = new BaseUnit(10, -10);
    boss = new BossUnit(400,-20);
    this->gameUnits.append(base);
    this->gameUnits.append(boss);
  //  this->gameUnits.append(new SwordsMan(100, 0));
}

QList<GameUnit *> GameLogic::getGameUnits()
{
    return this->gameUnits;
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
                if(boss->getX() - warriorUnit->getX() < 2 && boss->getHP() > 0){
                    warriorUnit->startFight();
                }
                if(!warriorUnit->getState()) {
                warriorUnit->move();
                } else {
                    boss->setHP(boss->getHP() - warriorUnit->getDamage());
                    if(boss->getHP() <= 0) {
                        this->gameUnits.removeOne(boss);
                     //   delete boss;
                        warriorUnit->stopFight();
                    }
                }
            } else {
                movableUnit->move();
           }
        }
        BossUnit *bossUnit = dynamic_cast<BossUnit *>(unit);
        if (bossUnit) {

        }
    }

    decCooldown();
    mine();
//    buyUnit();


    emit GameUpdated();
}

void GameLogic::decCooldown()
{
    if(cooldown > 0) {
        --cooldown;
    }
}

void GameLogic::buyUnit()
{
//only swordsmen for today
    if(!cooldown){
        if(base->getGold() >= SwordsMan::cost) {
            base->setGold(base->getGold() - SwordsMan::cost);
            this->gameUnits.append(new SwordsMan(100,0));
            cooldown = SwordsMan::cooldown;
        }
    }
}

void GameLogic::mine()
{
    base->setGold(base->getGold() + base->getMiners());
}

void GameLogic::buyMiner()
    {if(!cooldown){
        if(base->getGold() >= base->getMinerCost()) {
            base->buyMiner();
            this->gameUnits.append(new MinerUnit(20 + base->getMiners() * 60 , 20));
            cooldown = base->getMinerCooldown();
        }
    }
}


void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}
