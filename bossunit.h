#ifndef BOSSUNIT_H
#define BOSSUNIT_H

#include "staticunit.h"

class BossUnit : public StaticUnit
{
public:
    BossUnit();
    BossUnit(float x, float y);
    int getHP();
    void setHP(int hp);
private:
    void Initialize();
protected:
    int healthPoints;
    int strength;
    int range;
};
#endif // BOSSUNIT_H
