#ifndef MOVABLEUNIT_H
#define MOVABLEUNIT_H

#include "gameunit.h"

class MovableUnit : public GameUnit
{
public:
    MovableUnit();
    void moveIfNeeded();
    void setSpeed(float speed);
    void setDirectionForward(bool value);
protected:
    float speed;
    bool moving;
    bool isDirectionForward;
};

#endif // MOVABLEUNIT_H
