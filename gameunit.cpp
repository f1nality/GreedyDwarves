#include "gameunit.h"

GameUnit::GameUnit()
{
    this->currentFrame = 0;
}

float GameUnit::getX()
{
    return this->x;
}

float GameUnit::getY()
{
    return this->y;
}

QImage * GameUnit::getImage()
{
    return this->image;
}

int GameUnit::getWidth()
{
    return this->imageSize.width();
}

int GameUnit::getHeight()
{
    return this->imageSize.height();
}

size_t GameUnit::getCurrentFrame()
{
    return this->currentFrame;
}

void GameUnit::nextFrame()
{
    ++this->currentFrame;

    if (this->currentFrame == this->frames)
    {
        this->currentFrame = 0;
    }
}
