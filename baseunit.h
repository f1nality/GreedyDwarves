#ifndef BASEUNIT_H
#define BASEUNIT_H

#include "staticunit.h"

class BaseUnit : public StaticUnit
{
public:
    BaseUnit();
private:
    int healthPoints;
    int level;
};

#endif // BASEUNIT_H
