#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include <QTimer>
#include "gameunit.h"
#include "movableunit.h"
#include "swordsman.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic();
    QList<GameUnit *> getGameUnits();
    void ProcessEvents();
private:
    QTimer gameTimer;
    QList<GameUnit *> gameUnits;
public slots:
    void unitOfTimeElapsed();
signals:
    void GameUpdated();
};

#endif // GAMELOGIC_H
