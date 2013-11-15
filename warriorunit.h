#ifndef WARRIORUNIT_H
#define WARRIORUNIT_H

#include "movableunit.h"

class WarriorUnit : public MovableUnit
{
public:
    WarriorUnit();
    int getCooldown();
protected:
    int healthPoints;
    int cooldown;
};

#endif // WARRIORUNIT_H
