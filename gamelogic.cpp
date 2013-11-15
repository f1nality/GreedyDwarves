#include "gamelogic.h"
#include "baseunit.h"
#include "swordsman.h"
#include "bossunit.h"
#include "warriorunit.h"

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
    this->gameUnits.append(new SwordsMan(100, 0));
}

QList<GameUnit *> GameLogic::getGameUnits()
{
    return this->gameUnits;
}

void GameLogic::ProcessEvents()
{
    foreach (GameUnit *unit, gameUnits)
    {
        unit->nextFrame();

//        MovableUnit *movableUnit = dynamic_cast<MovableUnit *>(unit);

        SwordsMan *warriorUnit = dynamic_cast<SwordsMan *>(unit);
        if(warriorUnit)
        warriorUnit->move();


      /*  if (movableUnit)
        {
          //  WarriorUnit *warriorUnit = dynamic_cast<WarriorUnit *>(unit);
          //  warriorUnit->move();
            if (warriorUnit)
            {
                if(boss->getX() - warriorUnit->getX() < 50){
                    warriorUnit->fight();
                   // delete warriorUni
                   // this->gameUnits.append(new SwordsMan(100, 0));
                }
                if(!warriorUnit->getState()) {
              //  warriorUnit->move();
                }
            } else {
              //  movableUnit->move();
           //}
        }
*/    }
//    decCooldown();
  //  mine();
  //  buyUnit();


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
    {   if(cooldown){
        if(base->getGold() >= base->getMinerCost()) {
            base->buyMiner();
        }
    }
}

void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}
