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

void WarriorUnit::fight()
{
    ifFight = true;
}

void WarriorUnit::move()
{
    ifFight = false;
}

