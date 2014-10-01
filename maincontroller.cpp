#include "maincontroller.h"

#include <QQmlComponent>
#include <QQmlContext>

MainController::MainController(QObject *parent) :
    QObject(parent),
    mainWindow(new MainWindow(NULL, this)),
    newGame(new NewGame(NULL, this)),
    settings(new Settings(NULL, this))
{
    engine = new QQmlApplicationEngine(this);
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:///main.qml")));
    rootObject = component.create();

    mainWindow->setRootObject(rootObject);
    newGame->setRootObject(rootObject);
    settings->setRootObject(rootObject);

    engine->rootContext()->setContextProperty("mainController", this);
    engine->rootContext()->setContextProperty("mainWindow", mainWindow);
    engine->rootContext()->setContextProperty("newGame", newGame);
    engine->rootContext()->setContextProperty("settings", settings);

    showHomeScreen();
}

void MainController::showHomeScreen() {
    mainWindow->showHomeScreen();
}

void MainController::startNewGame() {
    newGame->showNewGamePage();
}

void MainController::showSettings() {
    settings->showSettingsPage();
}

MainController::~MainController() {
    delete rootObject;
    delete engine;
    delete mainWindow;
    delete newGame;
}
