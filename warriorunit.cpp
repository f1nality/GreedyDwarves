#include "warriorunit.h"


WarriorUnit::WarriorUnit()
{
    this->damage = 0;
}

int WarriorUnit::getRange()
{
    return range;
}

int WarriorUnit::getDamage()
{
    return damage;
}

int WarriorUnit::getState()
{
    return isAttacking;
}
/*
void WarriorUnit::startFight()
{
    isAttacking = true;
}

void WarriorUnit::stopFight()
{
    isAttacking = false;
}
*/
void WarriorUnit::attack(WarriorUnit *enemyUnit)
{
    enemyUnit->setHealthPoints(enemyUnit->getHealthPoints() - damage);

    if (enemyUnit->getHealthPoints() < 0)
    {
        isAttacking = false;
        moving = true;
    }
    else
    {
        isAttacking = true;
        moving = false;
    }
}

int WarriorUnit::getHealthPoints()
{
    return healthPoints;
}

void WarriorUnit::setHealthPoints(int healthPoints)
{
    this->healthPoints = healthPoints;
}


