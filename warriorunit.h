#ifndef WARRIORUNIT_H
#define WARRIORUNIT_H

#include "movableunit.h"

class WarriorUnit : public MovableUnit
{
public:
    WarriorUnit();
    static int getCost();
    int getCooldown();
protected:
    int cost;
    int healthPoints;
    int cooldown;
};

#endif // WARRIORUNIT_H
