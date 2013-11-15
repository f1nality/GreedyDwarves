#ifndef WARRIORUNIT_H
#define WARRIORUNIT_H

#include "movableunit.h"

class WarriorUnit : public MovableUnit
{
public:
    WarriorUnit();
    int getRange();
    int getDamage();
    int getState();
    void fight();
    void move();
protected:
    int healthPoints;
    int range;
    int damage;
    bool ifFight;
};

#endif // WARRIORUNIT_H
