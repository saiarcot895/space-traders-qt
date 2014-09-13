#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "newgame.h"

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();

    Q_INVOKABLE void startNewGame();
    Q_INVOKABLE void showSettings();

private:
    QQmlApplicationEngine* engine;
    QObject* rootObject;
    NewGame* newGame;

};

#endif // MAINWINDOW_H
