#include "planetnavigation.h"
#include <QVariant>

PlanetNavigation::PlanetNavigation(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject),
    galaxy(Galaxy::getInstance()),
    player(Player::getInstance())
{
}

void PlanetNavigation::setRootObject(QObject *rootObject) {
    this->rootObject = rootObject;
}

void PlanetNavigation::showPlanetNavigationPage() {
    Q_ASSERT(rootObject);
    rootObject->findChild<QObject*>("pageLoader")->setProperty("source", QStringLiteral("qrc:///planetNavigation.qml"));

    QObject* navigationRectangle = rootObject->findChild<QObject*>("planetNavigationScreen");

    QList<Planet> planets = player.getCurrentSystem().getPlanets();

    for (int i = 0; i < planets.size(); i++) {
        const Planet planet = planets.at(i);
        QMetaObject::invokeMethod(navigationRectangle, "createPlanetButtons",
                                  Q_ARG(QVariant, planet.getName()),
                                  Q_ARG(QVariant, planet.getColor()),
                                  Q_ARG(QVariant, 50));
    }
}
