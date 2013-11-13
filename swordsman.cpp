#include "swordsman.h"

SwordsMan::SwordsMan()
{
    this->image = new QImage(":/graphics/img.png");
    this->imageSize = QSize(32, 32);
    this->frames = 6;
    this->speed = 1;
}

SwordsMan::SwordsMan(float x, float y)
{
    this->image = new QImage(":/graphics/img.png");
    this->imageSize = QSize(32, 32);
    this->frames = 6;
    this->speed = 1;
    this->x = x;
    this->y = y;
}
