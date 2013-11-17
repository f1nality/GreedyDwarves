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

    this->frames.insert(0, 6);
    this->frames.insert(1, 2);
    this->frames.insert(2, 2);
    this->frames.insert(3, 2);
    this->frames.insert(4, 2);
    this->frames.insert(5, 2);
    this->frames.insert(6, 2);
    this->frames.insert(7, 2);
}
