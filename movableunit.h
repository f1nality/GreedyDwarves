#ifndef MOVABLEUNIT_H
#define MOVABLEUNIT_H

#include "gameunit.h"

class MovableUnit : public GameUnit
{
public:
    MovableUnit();
private:
    float speed;
};

#endif // MOVABLEUNIT_H
