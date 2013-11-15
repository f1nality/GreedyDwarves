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

int BossUnit::getHP()
{
    return healthPoints;
}

void BossUnit::setHP(int hp)
{
    healthPoints = hp;
}


void BossUnit::Initialize()
{
    this->image = new QImage(":/graphics/dragon.png");
    this->frameSize = QSize(200, 200);
    this->frames = 1;
    this->healthPoints = 10;
}
