#include "baseunit.h"

BaseUnit::BaseUnit()
{
    Initialize();
}

BaseUnit::BaseUnit(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void BaseUnit::setGold(int gold)
{
    if (gold > 100000)
    {
        this->gold = 100000;
    }
    else
    {
        this->gold = gold;
    }
}

int BaseUnit::getGold()
{
    return gold;
}

int BaseUnit::getMiners()
{
    return miners;
}

int BaseUnit::getMinerCost()
{
    return minerCost;
}

void BaseUnit::buyMiner()
{
    ++miners;
    gold = gold - minerCost;
    minerCost = 3 * minerCost;
}

void BaseUnit::Initialize()
{
    this->image = new QImage(":/graphics/house.png");
    this->frameSize = QSize(94, 83);
    //this->frames = 1;
    this->maxHealthPoints = 1000;
    this->healthPoints = maxHealthPoints;
    this->level = 1;
    this->gold = 30;
    this->miners = 1;
    this->minerCost = 1;
    this->damage = 0;

}
