#include "movableunit.h"

MovableUnit::MovableUnit()
{
    this->speed = 0;
}

void MovableUnit::move()
{
    x += speed;
}
