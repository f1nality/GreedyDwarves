#include "uicooldownbutton.h"

UICooldownButton::UICooldownButton(QImage *iconImage, QSize iconImageSize)
{
    this->x = x;
    this->y = y;
    this->backgroundImage = new QImage(":/graphics/order-button.png");
    this->frame = 0;
    this->iconImage = iconImage;
    this->iconImageSize = iconImageSize;
}

int UICooldownButton::getX()
{
    return x;
}

void UICooldownButton::setX(int x)
{
    this->x = x;
}

int UICooldownButton::getY()
{
    return y;
}

void UICooldownButton::setY(int y)
{
    this->y = y;
}

QImage *UICooldownButton::getBackgroundImage()
{
    return backgroundImage;
}

QSize UICooldownButton::getBackgroundImageSize()
{
    return QSize(42, 50);
}

QImage *UICooldownButton::getIconImage()
{
    return iconImage;
}

QSize UICooldownButton::getIconImageSize()
{
    return iconImageSize;
}

int UICooldownButton::getFrame()
{
    return frame;
}

void UICooldownButton::setHover(bool value)
{
    frame = (value) ? 1 : 0;
}
