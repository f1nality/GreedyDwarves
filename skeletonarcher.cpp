#include "skeletonarcher.h"

SkeletonArcher::SkeletonArcher()
{
    Initialize();
}

SkeletonArcher::SkeletonArcher(float x, float y)
{
    this->x = x;
    this->y = y;

    Initialize();
}

void SkeletonArcher::Initialize()
{
    this->image = new QImage(":/graphics/skeletonarcher.png");
    this->frameSize = QSize(57, 46);
    this->speed = 1;
    this->maxHealthPoints = 20;
    this->healthPoints = maxHealthPoints;
    this->damage = 1;
    this->range = 100;

    this->frames.insert(0, 3);
    this->frames.insert(1, 3);

    this->attackingFrames.insert(2, 3);
    this->attackingFrames.insert(3, 9);
    this->attackingFrames.insert(4, 3);
    this->attackingFrames.insert(5, 3);
    this->attackingFrames.insert(6, 3);
    this->attackingFrames.insert(7, 3);
    this->attackingFrames.insert(8, 3);
}
