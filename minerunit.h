#ifndef MINERUNIT_H
#define MINERUNIT_H

#include "staticunit.h"
#include "baseunit.h"

class MinerUnit : public StaticUnit
{
public:
    MinerUnit();
    MinerUnit(float x, float y, BaseUnit *base);
    static const int cooldown = 100;
    int getMiners();
private:
    BaseUnit *base;
    void Initialize();
};

#endif // MINERUNIT_H
