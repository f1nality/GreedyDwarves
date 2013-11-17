#include "bull.h"

Bull::Bull()
{
    Initialize();
}

Bull::Bull(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void Bull::Initialize()
{
    this->image = new QImage(":/graphics/bull.png");
    this->frameSize = QSize(58, 64);
    this->frames = 10;
    this->timePerFrame = 3;
    this->speed = 0.5;
    this->maxHealthPoints = 70;
    this->healthPoints = maxHealthPoints;
    this->damage = 1;
}

