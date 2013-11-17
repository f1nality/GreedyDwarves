#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "warriorunit.h"

class BaseUnit : public WarriorUnit
{
public:
    BaseUnit();
    BaseUnit(float x, float y);
    void setGold(int gold);
    int getGold();
    int getMiners();
    int getMinerCost();
    void buyMiner();
private:
    void Initialize();
protected:
    int level;
    int gold;
    int miners;
    int minerCost;
};

#endif // BASEUNIT_H
