#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QWidget>
#include <QPainter>

class GameCanvas : public QWidget
{
    Q_OBJECT
public:
    float position;
    explicit GameCanvas(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
};

#endif // GAMECANVAS_H