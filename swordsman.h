#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#include "warriorunit.h"

class SwordsMan : public WarriorUnit
{
public:
    SwordsMan();
    SwordsMan(float x, float y);
    static const int cost = 40;
    static const int cooldown = 50;
private:
    void Initialize();
};

#endif // SWORDSMAN_H
