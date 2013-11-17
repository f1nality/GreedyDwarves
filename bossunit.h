#ifndef BOSSUNIT_H
#define BOSSUNIT_H

#include "warriorunit.h"

class BossUnit : public WarriorUnit
{
public:
    BossUnit();
    BossUnit(float x, float y);
private:
    void Initialize();
protected:
    int strength;
    int range;
};
#endif // BOSSUNIT_H
