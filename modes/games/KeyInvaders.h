#ifndef KEYINVADERS_H
#define KEYINVADERS_H

#include "../MorseMode.h"
#include "MGameMode.h"
#include "HighScores.h"

#include <QtCore/QList>
#include <QtCore/QList>
#include <QtCore/QTime>
#include <QtGui/QGraphicsView>
#include <QtCore/QTimer>

class KeyInvaders : public MorseMode, MGameMode
{
    Q_OBJECT

public:
    KeyInvaders(Morse *parent, Ui::MainWindow *main);


    virtual void switchToMode();
    virtual void modeMenus();
    void setupWidgets();

    // standard functions
    virtual QString helpText();
    virtual QString name();
    virtual QString icon();
    virtual void gameOver();


public slots:
    virtual void handleKeyPress(QChar letterPressed);
    virtual void handleKeyRelease(QChar letterPressed);
    virtual void play();
    virtual void stop();

    void advanceFrame();

private:
    HighScores  m_scores;
    int m_keyCount;
    QTime m_startTime;
    QList<int> m_keyedTimes;
    QGraphicsView *m_graph;

    QTimer invadingTimer;
};

#endif // KEYINVADERS_H
