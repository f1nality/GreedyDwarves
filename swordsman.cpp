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
    this->frames = 6;
    this->timePerFrame = 2;
    this->speed = 1;
}

