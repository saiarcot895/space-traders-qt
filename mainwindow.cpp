#include "mainwindow.h"

#include <QQmlComponent>
#include <QQmlContext>

MainWindow::MainWindow(QObject *parent) :
    QObject(parent)
{
    engine = new QQmlApplicationEngine(this);
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:///main.qml")));
    rootObject = component.create();

    engine->rootContext()->setContextProperty("mainWindow", this);
}

MainWindow::~MainWindow() {
    delete rootObject;
    delete engine;
}
