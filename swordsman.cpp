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
    this->image = new QImage(":/graphics/img.png");
    this->imageSize = QSize(32, 32);
    this->frames = 6;
    this->speed = 1;
}

