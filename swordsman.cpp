#include "swordsman.h"

SwordsMan::SwordsMan()
{
    Initialize();
}

SwordsMan::SwordsMan(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void SwordsMan::Initialize()
{
    this->image = new QImage(":/graphics/swordsman.png");
    this->frameSize = QSize(32, 32);
    this->speed = 1;
    this->maxHealthPoints = 200;
    this->healthPoints = maxHealthPoints;
    this->damage = 1;

    this->frames.insert(0, 3);
    this->frames.insert(1, 3);
    this->frames.insert(2, 3);

    this->attackingFrames.insert(3, 3);
    this->attackingFrames.insert(4, 3);
    this->attackingFrames.insert(5, 3);
}

