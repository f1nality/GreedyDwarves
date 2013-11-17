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
    //void startFight();
    //void stopFight();
    void attack(WarriorUnit *enemyUnit);
    int getHealthPoints();
    void setHealthPoints(int healthPoints);
    int getMaxHealthPoints();
protected:
    int healthPoints;
    int maxHealthPoints;
    int range;
    int damage;
    bool isAttacking;
};

#endif // WARRIORUNIT_H
