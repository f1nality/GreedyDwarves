#include "gamelogic.h"
#include "baseunit.h"
#include "swordsman.h"

GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(unitOfTimeElapsed()));

    gameTimer.setInterval(50);
    gameTimer.start();

    cooldown = 0;

    base = new BaseUnit(10, -10);
    this->gameUnits.append(base);
    //this->gameUnits.append(new SwordsMan(100, 0));
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

        MovableUnit *movableUnit = dynamic_cast<MovableUnit *>(unit);

        if (movableUnit)
        {
            movableUnit->move();
        }
    }
    decCooldown();
    mine();
    buyUnit();


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
    if(cooldown){
        if(base->getGold() >= SwordsMan.cost) {
            base->setGold(base->getGold() - SwordsMan.cost);
            this->gameUnits.append(new SwordsMan(100,0));
            cooldown = SwordsMan.getCooldown();
        }
    }
}

void GameLogic::mine()
{
    base->setGold(base->getGold() + base->getMiners());
}

void GameLogic::buyMiner()
    {   if(cooldown){
        if(base->getGold() >= base->minerCost) {
            base->miners ++;
            base->setGold(base->getGold() - base->minerCost);
            base->minerCost = 2 * base->minerCost;
        }
    }
}

void GameLogic::unitOfTimeElapsed()
{
    ProcessEvents();
}
