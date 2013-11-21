#include "gamecanvas.h"
#include <QDebug>
GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    ROAD_Y = 195;

    setMouseTracking(true);
}

void GameCanvas::setGameLogic(GameLogic *gameLogic)
{
    this->gameLogic = gameLogic;
}

void GameCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 0, QImage(":/graphics/background.png"), 0, 0, -1, -1, 0);

    drawGameUnits(painter);
    drawCooldownButtons(painter);
    drawGold(painter);
}

int GameCanvas::getCooldownButtonX(size_t index)
{
    return 10 + (UICooldownButton::getBackgroundImageSize().width() + 4) * index;
}

int GameCanvas::getCooldownButtonY(size_t)
{
    return 10;
}

void GameCanvas::mousePressEvent(QMouseEvent *mouseEvent)
{
    mousePressedX = mouseEvent->x();
    mousePressedY = mouseEvent->y();
}

void GameCanvas::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    size_t i = 0;

    foreach (UICooldownButton *button, gameLogic->getCooldownButtons())
    {
        int buttonX = getCooldownButtonX(i);
        int buttonY = getCooldownButtonY(i);

        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), buttonX, buttonY, button->getBackgroundImageSize()))
        {
            if (isPointInArea(mousePressedX, mousePressedY, buttonX, buttonY, button->getBackgroundImageSize()) && button->isActive())
            {
                emit button->pressed();

                break;
            }
        }

        ++i;
    }
}

void GameCanvas::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    size_t i = 0;

    foreach (UICooldownButton *button, gameLogic->getCooldownButtons())
    {
        int buttonX = getCooldownButtonX(i);
        int buttonY = getCooldownButtonY(i);

        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), buttonX, buttonY, button->getBackgroundImageSize()))
        {
            button->setHover(true);
        }
        else
        {
            button->setHover(false);
        }

        ++i;
    }
}

bool GameCanvas::isPointInArea(int x, int y, int rect_x, int rect_y, QSize rect_size)
{
    return (x >= rect_x && y >= rect_y && x < rect_x + rect_size.width() && y < rect_y + rect_size.height());
}

void GameCanvas::drawGameUnits(QPainter &painter)
{
    foreach (GameUnit *unit, gameLogic->getGameUnits())
    {
        painter.drawImage((int)unit->getX(), ROAD_Y - unit->getHeight() - (int)unit->getY(), *unit->getImage(), unit->getCurrentFrame() * unit->getWidth(), 0, unit->getWidth(), unit->getHeight());

        WarriorUnit *warriorUnit = dynamic_cast<WarriorUnit *>(unit);

        if (warriorUnit)
        {
            drawHealthBar(painter, warriorUnit);
        }

        MinerUnit *minerUnit = dynamic_cast<MinerUnit *>(unit);

        if (minerUnit)
        {
            drawMinersCount(painter, minerUnit);
        }
    }
}

void GameCanvas::drawHealthBar(QPainter &painter, WarriorUnit *unit)
{
    int padding_left = 1;
    int padding_right = 1;
    int bottom_margin = 10;
    int border_width = 1;
    int bar_height = 5;

    painter.fillRect((int)unit->getX() + padding_left, ROAD_Y - unit->getHeight() - (int)unit->getY() - bottom_margin, unit->getWidth() - padding_left - padding_right, bar_height, QBrush(Qt::black));
    painter.fillRect((int)unit->getX() + padding_left + border_width, ROAD_Y - unit->getHeight() - (int)unit->getY() - bottom_margin + border_width, (unit->getWidth() - border_width * 2 - padding_left - padding_right) * ((float)unit->getHealthPoints() / unit->getMaxHealthPoints()), bar_height - border_width * 2, QBrush(QColor(102, 204, 102, 255)));
}

void GameCanvas::drawMinersCount(QPainter &painter, MinerUnit *unit)
{
    painter.fillRect((int)unit->getX(), ROAD_Y - unit->getHeight() - (int)unit->getY() - 16, 16, 16, QBrush(Qt::black));
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Courier New", 8));
    painter.drawText((int)unit->getX(), ROAD_Y - unit->getHeight() - (int)unit->getY() - 16, 16, 16, Qt::AlignCenter, QString("%1").arg(unit->getMiners()), NULL);
}

void GameCanvas::drawCooldownButtons(QPainter &painter)
{
    size_t i = 0;

    foreach (UICooldownButton *button, gameLogic->getCooldownButtons())
    {
        painter.drawImage(getCooldownButtonX(i), getCooldownButtonY(i), *button->getBackgroundImage(), button->getFrame() * button->getBackgroundImageSize().width(), 0, button->getBackgroundImageSize().width(), button->getBackgroundImageSize().height());
        ++i;
    }
}

void GameCanvas::drawGold(QPainter &painter)
{
    painter.drawImage(640 - 110 - 10, 10, QImage(":/graphics/gold.png"), 0, 0, -1, -1);
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Courier New", 10));
    painter.drawText(640 - 110 - 10 + 6, 10 + 7, 75, 14, Qt::AlignCenter, QString("%1").arg(gameLogic->getGold()), NULL);
}

void GameCanvas::onGameUpdated()
{
    repaint();
}
