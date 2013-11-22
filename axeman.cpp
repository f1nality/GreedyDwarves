#include "axeman.h"

AxeMan::AxeMan()
{
    Initialize();
}

AxeMan::AxeMan(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void AxeMan::Initialize()
{
    this->image = new QImage(":/graphics/axeman.png");
    this->frameSize = QSize(44, 29);
    this->speed = 0.8;
    this->maxHealthPoints = 300;
    this->healthPoints = maxHealthPoints;
    this->damage = 2;

    this->frames.insert(0, 3);
    this->frames.insert(1, 3);

    this->attackingFrames.insert(2, 3);
    this->attackingFrames.insert(3, 3);
    this->attackingFrames.insert(4, 3);
    this->attackingFrames.insert(5, 3);
}

