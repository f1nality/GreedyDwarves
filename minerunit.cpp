#include "minerunit.h"

MinerUnit::MinerUnit()
{
    Initialize();
}


MinerUnit::MinerUnit(float x, float y, BaseUnit *base)
{
    this->x = x;
    this->y = y;
    this->base = base;

    Initialize();
}

int MinerUnit::getMiners()
{
    return base->getMiners();
}

void MinerUnit::Initialize()
{
    this->image = new QImage(":/graphics/miner.png");
    this->frameSize = QSize(40, 39);
    this->frames = 8;
    this->timePerFrame = 2;
}
