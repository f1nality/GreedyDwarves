#include "gameunit.h"

GameUnit::GameUnit()
{
    this->currentFrame = 0;
    this->timeSinceCurrentFrame = 0;
}

float GameUnit::getX()
{
    return this->x;
}

float GameUnit::getY()
{
    return this->y;
}

QImage *GameUnit::getImage()
{
    return this->image;
}

int GameUnit::getWidth()
{
    return this->frameSize.width();
}

int GameUnit::getHeight()
{
    return this->frameSize.height();
}

size_t GameUnit::getCurrentFrame()
{
    return this->currentFrame;
}

void GameUnit::nextFrame()
{
    ++timeSinceCurrentFrame;

    if (frames.contains(currentFrame) && timeSinceCurrentFrame == frames[currentFrame])
    {
        if (frames.contains(currentFrame + 1))
        {
            ++currentFrame;
            timeSinceCurrentFrame = 0;
        }
        else
        {
            currentFrame = frames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
}
