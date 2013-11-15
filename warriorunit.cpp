#include "warriorunit.h"


WarriorUnit::WarriorUnit()
{

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
    return ifFight;
}

void WarriorUnit::startFight()
{
    ifFight = true;
}

void WarriorUnit::stopFight()
{
    ifFight = false;
}


