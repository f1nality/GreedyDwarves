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
    this->speed = 0.5;
    this->maxHealthPoints = 70;
    this->healthPoints = maxHealthPoints;
    this->damage = 1;

    this->frames.insert(0, 3);
    this->frames.insert(1, 3);
    this->frames.insert(2, 3);
    this->frames.insert(3, 3);
    this->frames.insert(4, 3);
    this->frames.insert(5, 3);
    this->frames.insert(6, 3);
    this->frames.insert(7, 3);
    this->frames.insert(8, 3);
    this->frames.insert(9, 3);
}

