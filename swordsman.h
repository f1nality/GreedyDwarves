#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#include "warriorunit.h"

class SwordsMan : public WarriorUnit
{
public:
    SwordsMan();
    SwordsMan(float x, float y);
private:
    void Initialize();
};

#endif // SWORDSMAN_H
