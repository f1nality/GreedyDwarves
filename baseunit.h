#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "staticunit.h"

class BaseUnit : public StaticUnit
{
public:
    BaseUnit();
    BaseUnit(float x, float y);
private:
    void Initialize();
protected:
    int healthPoints;
    int level;
};

#endif // BASEUNIT_H
