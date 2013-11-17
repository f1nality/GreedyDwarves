#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QWidget>
#include <QImage>
#include <QPainter>

class UICooldownButton : public QWidget
{
    Q_OBJECT
public:
    UICooldownButton(QImage iconImage, QSize iconImageSize, int cooldownOverall);
    QImage *getBackgroundImage();
    static QSize getBackgroundImageSize();
    int getFrame();
    void setHover(bool value);
    void setCooldownElapsed(int cooldownElapsed);
    bool isActive();
    void updateCooldownElapsedIfNeeded();
    void resetCooldownElapsed();
private:
    QImage *backgroundImage;
    int frame;
    QImage iconImage;
    QImage iconImageGrayscale;
    QSize iconImageSize;
    size_t cooldownElapsed;
    size_t cooldownOverall;
    void repaint();
    void convertToGrayScale(QImage &image);
signals:
    void pressed();
};

#endif // UIBUTTON_H
