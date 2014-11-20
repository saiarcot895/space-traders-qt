#include "navigation.h"
#include <QVariant>
#include <QtMath>

Navigation::Navigation(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject),
    galaxy(Galaxy::getInstance()),
    player(Player::getInstance())
{
}

void Navigation::setRootObject(QObject *rootObject) {
    this->rootObject = rootObject;
}

void Navigation::showNavigationPage() {
    Q_ASSERT(rootObject);
    rootObject->findChild<QObject*>("pageLoader")->setProperty("source", QStringLiteral("qrc:///navigation.qml"));

    QObject* navigationRectangle = rootObject->findChild<QObject*>("navigationScreen");
    QObject* mapRegion = rootObject->findChild<QObject*>("mapRegion");

    for (int i = 0; i < galaxy.getSolarSystems().size(); i++) {
        const SolarSystem system = galaxy.getSolarSystems().at(i);
#ifndef Q_OS_ANDROID
        QMetaObject::invokeMethod(navigationRectangle, "createPlanetButtons",
#else
        QMetaObject::invokeMethod(navigationRectangle, "createPlanetButtonsAndroid",
#endif
                                  Q_ARG(QVariant, system.getName()),
                                  Q_ARG(QVariant, system.getColor()),
                                  Q_ARG(QVariant, player.getCurrentSystem() == system),
                                  Q_ARG(QVariant, (double) system.getX() / 1000 * (mapRegion->property("contentWidth").toInt() - 32 * 1.5)),
                                  Q_ARG(QVariant, (double) system.getY() / 1000 * (mapRegion->property("contentHeight").toInt() - 32 * 1.5)));
    }
}

int Navigation::getNumPlanets(QString solarSystem) const {
    return galaxy.getSolarSystem(solarSystem).getPlanets().size();
}

bool Navigation::isTravelableToSolarSystem(QString solarSystem) const {
    SolarSystem origin = player.getCurrentSystem();
    SolarSystem destination = galaxy.getSolarSystem(solarSystem);
    Ship ship = player.getShip();

    return galaxy.getDistanceBetweenSolarSystems(origin, destination) < ship.getFuel();
}

void Navigation::travelToSolarSystem(QString solarSystem) {
    SolarSystem origin = player.getCurrentSystem();
    SolarSystem destination = galaxy.getSolarSystem(solarSystem);
    Ship ship = player.getShip();

    player.setCurrentSystem(galaxy.getSolarSystem(solarSystem));
    int planetIndex = qrand() % player.getCurrentSystem().getPlanets().size();
    player.setCurrentPlanet(player.getCurrentSystem().getPlanets().values().at(planetIndex));
    ship.setFuel(ship.getFuel() - galaxy.getDistanceBetweenSolarSystems(origin, destination));

    QObject* navigationRectangle = rootObject->findChild<QObject*>("navigationScreen");

    QMetaObject::invokeMethod(navigationRectangle, "setNewCurrentPlanet",
                              Q_ARG(QVariant, destination.getName()));
}
