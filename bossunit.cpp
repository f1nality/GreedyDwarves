#include "bossunit.h"

BossUnit::BossUnit()
{
    Initialize();
}


BossUnit::BossUnit(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void BossUnit::Initialize()
{
    this->image = new QImage(":/graphics/dragon.png");
    this->frameSize = QSize(120, 87);
    this->maxHealthPoints = 1000;
    this->healthPoints = maxHealthPoints;
    this->moving = false;
    this->damage = 2;

    this->frames.insert(0, 4);
    this->frames.insert(1, 4);
    this->frames.insert(2, 4);
    this->frames.insert(3, 4);

    this->attackingFrames.insert(4, 3);
    this->attackingFrames.insert(5, 3);
    this->attackingFrames.insert(6, 3);
    this->attackingFrames.insert(7, 3);
    this->attackingFrames.insert(8, 3);
    this->attackingFrames.insert(9, 3);
}
