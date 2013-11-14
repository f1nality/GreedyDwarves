#include "baseunit.h"

BaseUnit::BaseUnit()
{
    this->image = new QImage(":/graphics/base.png");
    this->frameSize = QSize(32, 32);
    this->frames = 1;
    this->healthPoints = 100;
    this->level = 1;
}
