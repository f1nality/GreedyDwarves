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
    this->frames = 4;
    this->timePerFrame = 4;
    this->maxHealthPoints = 30;
    this->healthPoints = maxHealthPoints;
    this->moving = false;
}
