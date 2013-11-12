#include "gamecanvas.h"

GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
}

void GameCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::darkGreen);
    painter.drawRect(0, 0, 320, 240);

    painter.drawImage(position, 0, QImage(":/graphics/img.png"), 0, 30, 30, 30, 0);
}
