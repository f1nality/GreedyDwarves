#include "warriorunit.h"
#include <QDebug>
WarriorUnit::WarriorUnit()
{
    this->damage = 0;
    this->range = 0;
}

int WarriorUnit::getRange()
{
    return range;
}

int WarriorUnit::getDamage()
{
    return damage;
}

void WarriorUnit::attack(WarriorUnit *enemyUnit)
{
    setAttacking(true);

    enemyUnit->setHealthPoints(enemyUnit->getHealthPoints() - damage);

    if (enemyUnit->getHealthPoints() < 0)
    {
        setAttacking(false);
        moving = true;
    }
    else
    {
        setAttacking(true);
        moving = false;
    }
}

void WarriorUnit::setAttacking(bool isAttacking)
{
    if (!this->isAttacking && isAttacking)
    {
        if (attackingFrames.count())
        {
            currentFrame = attackingFrames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
    else if (this->isAttacking && !isAttacking)
    {
        currentFrame = frames.keys().first();
        timeSinceCurrentFrame = 0;
    }

    this->isAttacking = isAttacking;
}

int WarriorUnit::getHealthPoints()
{
    return healthPoints;
}

void WarriorUnit::setHealthPoints(int healthPoints)
{
    this->healthPoints = healthPoints;
}

int WarriorUnit::getMaxHealthPoints()
{
    return maxHealthPoints;
}

void WarriorUnit::nextFrame()
{
    ++timeSinceCurrentFrame;

    if (isAttacking && attackingFrames.contains(currentFrame) && timeSinceCurrentFrame == attackingFrames[currentFrame])
    {
        if (attackingFrames.contains(currentFrame + 1))
        {
            ++currentFrame;
            timeSinceCurrentFrame = 0;
        }
        else
        {
            currentFrame = attackingFrames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
    else if (!isAttacking && frames.contains(currentFrame) && timeSinceCurrentFrame == frames[currentFrame])
    {
        if (frames.contains(currentFrame + 1))
        {
            ++currentFrame;
            timeSinceCurrentFrame = 0;
        }
        else
        {
            currentFrame = frames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
}


