#ifndef SKELETONARCHER_H
#define SKELETONARCHER_H

#include "warriorunit.h"

class SkeletonArcher : public WarriorUnit
{
public:
    SkeletonArcher();
    SkeletonArcher(float x, float y);
private:
    void Initialize();
};

#endif // SKELETONARCHER_H
