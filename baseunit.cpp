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
    this->gold = gold;
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
    minerCost = 2 * minerCost;
}

void BaseUnit::Initialize()
{
    this->image = new QImage(":/graphics/house.png");
    this->frameSize = QSize(94, 83);
    this->frames = 1;
    this->healthPoints = 100;
    this->level = 1;
    this->gold = 30;
    this->miners = 1;
    this->minerCost = 100;
}
