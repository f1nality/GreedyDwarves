#include "movableunit.h"

MovableUnit::MovableUnit()
{
    this->speed = 0;
    this->moving = true;
    this->isDirectionForward = true;
}

void MovableUnit::moveIfNeeded()
{
    if (moving)
    {
        if (isDirectionForward)
        {
            x += speed;
        }
        else
        {
            x -= speed;
        }
    }
}

void MovableUnit::setSpeed(float speed)
{
    this->speed = speed;
}

void MovableUnit::setDirectionForward(bool value)
{
    isDirectionForward = value;
}
