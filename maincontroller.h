#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "newgame.h"
#include "mainwindow.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = 0);
    ~MainController();

    Q_INVOKABLE void showHomeScreen();
    Q_INVOKABLE void startNewGame();
    Q_INVOKABLE void showSettings();

private:
    QQmlApplicationEngine* engine;
    QObject* rootObject;

    MainWindow* mainWindow;
    NewGame* newGame;

};

#endif // MAINCONTROLLER_H
