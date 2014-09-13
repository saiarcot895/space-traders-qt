#include "mainwindow.h"

#include <QQmlComponent>
#include <QQmlContext>

MainWindow::MainWindow(QObject *parent) :
    QObject(parent),
    newGame(new NewGame(NULL, this))
{
    engine = new QQmlApplicationEngine(this);
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:///main.qml")));
    rootObject = component.create();

    newGame->setRootObject(rootObject);

    engine->rootContext()->setContextProperty("mainWindow", this);
    engine->rootContext()->setContextProperty("newGame", newGame);
}

void MainWindow::startNewGame() {
    newGame->showNewGamePage();
}

void MainWindow::showSettings() {

}

MainWindow::~MainWindow() {
    delete rootObject;
    delete engine;
    delete newGame;
}
