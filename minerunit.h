#ifndef MINERUNIT_H
#define MINERUNIT_H

#include "staticunit.h"

class MinerUnit : public StaticUnit
{
public:
    MinerUnit();
    MinerUnit(float x, float y);
    static const int cooldown = 100;
private:
    void Initialize();
};

#endif // MINERUNIT_H
