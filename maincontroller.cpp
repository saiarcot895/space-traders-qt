#include "maincontroller.h"

#include <QQmlComponent>
#include <QQmlContext>

MainController::MainController(QObject *parent) :
    QObject(parent),
    mainWindow(new MainWindow(NULL, this)),
    newGame(new NewGame(NULL, this)),
    settings(new Settings(NULL, this)),
    navigation(new Navigation(NULL, this)),
    marketplace(new Marketplace(NULL, this))
{
    engine = new QQmlApplicationEngine(this);
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:///main.qml")));
    rootObject = component.create();

    mainWindow->setRootObject(rootObject);
    newGame->setRootObject(rootObject);
    settings->setRootObject(rootObject);
    navigation->setRootObject(rootObject);
    marketplace->setRootObject(rootObject);

    engine->rootContext()->setContextProperty("mainController", this);
    engine->rootContext()->setContextProperty("mainWindow", mainWindow);
    engine->rootContext()->setContextProperty("newGame", newGame);
    engine->rootContext()->setContextProperty("settings", settings);
    engine->rootContext()->setContextProperty("navigation", navigation);
    engine->rootContext()->setContextProperty("marketplace", marketplace);

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

void MainController::showNavigationPage() {
    navigation->showNavigationPage();
}

void MainController::showMarketplace() {
    marketplace->showMarketplace();
}

MainController::~MainController() {
    delete rootObject;
    delete engine;
    delete mainWindow;
    delete newGame;
}
