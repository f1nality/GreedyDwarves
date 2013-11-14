#include "baseunit.h"

BaseUnit::BaseUnit()
{
    Initialize();
}

BaseUnit::BaseUnit(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void BaseUnit::Initialize()
{
    this->image = new QImage(":/graphics/house.png");
    this->frameSize = QSize(94, 83);
    this->frames = 1;
    this->healthPoints = 100;
    this->level = 1;
}
