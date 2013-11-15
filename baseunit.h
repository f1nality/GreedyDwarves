#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "staticunit.h"

class BaseUnit : public StaticUnit
{
public:
    BaseUnit();
    BaseUnit(float x, float y);
    void setGold(int gold);
    int getGold();
    int getMiners();
    int getMinerCost();
    void buyMiner();
    int getMinerCooldown();

private:
    void Initialize();
protected:
    int healthPoints;
    int level;
    int gold;
    int miners;
    int minerCost;
    int minerCooldown;
};

#endif // BASEUNIT_H
