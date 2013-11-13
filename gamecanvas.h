#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>

class GameCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit GameCanvas(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
};

#endif // GAMECANVAS_H
