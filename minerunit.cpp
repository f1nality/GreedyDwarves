#include "minerunit.h"

MinerUnit::MinerUnit()
{
    Initialize();
}


MinerUnit::MinerUnit(float x, float y)
{
    this->x = x;
    this->y = y;

    Initialize();
}

void MinerUnit::Initialize()
{
    this->image = new QImage(":/graphics/miner.png");
    this->frameSize = QSize(85, 80);
    this->frames = 8;
    this->timePerFrame = 3;
}
