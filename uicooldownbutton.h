#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QWidget>
#include <QImage>

class UICooldownButton : public QWidget
{
    Q_OBJECT
public:
    UICooldownButton(QImage *iconImage, QSize iconImageSize);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    QImage *getBackgroundImage();
    static QSize getBackgroundImageSize();
    QImage *getIconImage();
    QSize getIconImageSize();
    int getFrame();
    void setHover(bool value);
private:
    int x;
    int y;
    QImage *backgroundImage;
    int frame;
    QImage *iconImage;
    QSize iconImageSize;
signals:
    void pressed();
};

#endif // UIBUTTON_H
