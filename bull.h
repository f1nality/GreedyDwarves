#ifndef BULL_H
#define BULL_H

#include "warriorunit.h"

class Bull : public WarriorUnit
{
public:
    Bull();
    Bull(float x, float y);
private:
    void Initialize();
};

#endif // BULL_H
