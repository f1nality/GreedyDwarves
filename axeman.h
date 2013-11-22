#ifndef AXEMAN_H
#define AXEMAN_H

#include "warriorunit.h"

class AxeMan : public WarriorUnit
{
public:
    AxeMan();
    AxeMan(float x, float y);
    static const int cost = 60;
    static const int cooldown = 70;
private:
    void Initialize();
};

#endif // AXEMAN_H
