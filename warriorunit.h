#ifndef WARRIORUNIT_H
#define WARRIORUNIT_H

#include "movableunit.h"

class WarriorUnit : public MovableUnit
{
public:
    WarriorUnit();
    int getRange();
    int getDamage();
    //int getState();
    //void startFight();
    //void stopFight();
    void attack(WarriorUnit *enemyUnit);
    int getHealthPoints();
    void setHealthPoints(int healthPoints);
    int getMaxHealthPoints();
    virtual void nextFrame();
    void setAttacking(bool isAttacking);
protected:
    int healthPoints;
    int maxHealthPoints;
    int range;
    int damage;
    bool isAttacking;
    QMap<size_t, size_t> attackingFrames;
private:

};

#endif // WARRIORUNIT_H
