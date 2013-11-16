#include "uicooldownbutton.h"

UICooldownButton::UICooldownButton(QImage *iconImage, QSize iconImageSize, int cooldownOverall)
{
    this->backgroundImage = new QImage(getBackgroundImageSize().width() * 2, getBackgroundImageSize().height(), QImage::Format_ARGB32);
    this->frame = 0;
    this->iconImage = iconImage;
    this->iconImageSize = iconImageSize;
    this->cooldownElapsed = cooldownOverall;
    this->cooldownOverall = cooldownOverall;

    repaint();
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
    return (cooldownElapsed < cooldownOverall) ? 0 : frame;
}

void UICooldownButton::setHover(bool value)
{
    frame = (value) ? 1 : 0;
}

void UICooldownButton::setCooldownElapsed(int cooldownElapsed)
{
    this->cooldownElapsed = cooldownElapsed;

    repaint();
}

bool UICooldownButton::isActive()
{
    return cooldownElapsed == cooldownOverall;
}

void UICooldownButton::updateCooldownElapsedIfNeeded()
{
    if (cooldownElapsed < cooldownOverall)
    {
        ++cooldownElapsed;
        repaint();
    }
}

void UICooldownButton::resetCooldownElapsed()
{
    cooldownElapsed = 0;
    repaint();
}

void UICooldownButton::repaint()
{
    QPainter painter(backgroundImage);

    painter.drawImage(0, 0, QImage(":/graphics/order-button.png"), 0, 0, -1, -1);
    painter.drawImage(getBackgroundImageSize().width() / 2 - iconImageSize.width() / 2, getBackgroundImageSize().width() / 2 - iconImageSize.height() / 2, *iconImage, 0, 0, iconImageSize.width(), iconImageSize.height());
    painter.drawImage(getBackgroundImageSize().width() + getBackgroundImageSize().width() / 2 - iconImageSize.width() / 2, getBackgroundImageSize().width() / 2 - iconImageSize.height() / 2, *iconImage, 0, 0, iconImageSize.width(), iconImageSize.height());

    float cooldownPercentage = (float)cooldownElapsed / cooldownOverall;

    QBrush brush = QBrush(QColor(102, 204, 102, 255));

    if (cooldownPercentage < 1)
    {
        brush = QBrush(QColor(153, 204, 153, 255));
    }

    painter.fillRect(4, getBackgroundImageSize().height() - 9, 34 * cooldownPercentage, 5, brush);
    painter.fillRect(getBackgroundImageSize().width() + 4, getBackgroundImageSize().height() - 9, 34 * cooldownPercentage, 5, brush);
}
