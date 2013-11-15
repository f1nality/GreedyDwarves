#include "gamecanvas.h"
#include <QDebug>
GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    ROAD_Y = 195;

    UICooldownButton *swordsManButton1 = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32));
    UICooldownButton *swordsManButton2 = new UICooldownButton(new QImage(":/graphics/swordsman.png"), QSize(32, 32));

    QObject::connect(swordsManButton1, SIGNAL(pressed()), this, SLOT(onCooldownButtonPressed()));
    QObject::connect(swordsManButton2, SIGNAL(pressed()), this, SLOT(onCooldownButtonPressed()));

    addCooldownButton(swordsManButton1);
    addCooldownButton(swordsManButton2);

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

    foreach (GameUnit *unit, gameLogic->getGameUnits())
    {
        painter.drawImage((int)unit->getX(), ROAD_Y - unit->getHeight() - (int)unit->getY(), *unit->getImage(), unit->getCurrentFrame() * unit->getWidth(), 0, unit->getWidth(), unit->getHeight());
    }

    foreach (UICooldownButton *button, cooldownButtons)
    {
        painter.drawImage(button->getX(), button->getY(), *button->getBackgroundImage(), button->getFrame() * button->getBackgroundImageSize().width(), 0, button->getBackgroundImageSize().width(), button->getBackgroundImageSize().height());
        painter.drawImage(button->getX() + button->getBackgroundImageSize().width() / 2 - button->getIconImageSize().width() / 2, button->getY() + button->getBackgroundImageSize().width() / 2 - button->getIconImageSize().height() / 2, *button->getIconImage(), 0, 0, button->getIconImageSize().width(), button->getIconImageSize().height());

        QBrush brush = QBrush(QColor(102, 204, 102, 255));
        //QBrush brush = QBrush(QColor(153, 204, 153, 255));
        painter.fillRect(button->getX() + 4, button->getY() + button->getBackgroundImageSize().height() - 9, 34, 5, brush);
    }

    painter.drawImage(640 - 110 - 10, 10, QImage(":/graphics/gold.png"), 0, 0, -1, -1);
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Courier New", 10));
    painter.drawText(640 - 110 - 10 + 6, 10 + 7, 75, 14, Qt::AlignCenter, QString("%1").arg(gameLogic->getGold()), NULL);
}

void GameCanvas::addCooldownButton(UICooldownButton *button)
{
    button->setX(10 + (UICooldownButton::getBackgroundImageSize().width() + 4) * cooldownButtons.length());
    button->setY(10);

    cooldownButtons.append(button);
}

void GameCanvas::mousePressEvent(QMouseEvent *mouseEvent)
{
    mousePressedX = mouseEvent->x();
    mousePressedY = mouseEvent->y();
}

void GameCanvas::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    foreach (UICooldownButton *button, cooldownButtons)
    {
        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), button->getX(), button->getY(), button->getBackgroundImageSize()))
        {
            if (isPointInArea(mousePressedX, mousePressedY, button->getX(), button->getY(), button->getBackgroundImageSize()))
            {
                emit button->pressed();

                break;
            }
        }
    }
}

void GameCanvas::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    foreach (UICooldownButton *button, cooldownButtons)
    {
        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), button->getX(), button->getY(), button->getBackgroundImageSize()))
        {
            button->setHover(true);
        }
        else
        {
            button->setHover(false);
        }
    }
}

bool GameCanvas::isPointInArea(int x, int y, int rect_x, int rect_y, QSize rect_size)
{
    return (x >= rect_x && y >= rect_y && x < rect_x + rect_size.width() && y < rect_y + rect_size.height());
}

void GameCanvas::onGameUpdated()
{
    repaint();
}

void GameCanvas::onCooldownButtonPressed()
{
    this->gameLogic->buy();
}
