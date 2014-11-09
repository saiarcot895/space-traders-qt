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
        QMetaObject::invokeMethod(navigationRectangle, "createPlanetButtons",
                                  Q_ARG(QVariant, system.getName()),
                                  Q_ARG(QVariant, system.getColor()),
                                  Q_ARG(QVariant, (double) system.getX() / 1000 * (mapRegion->property("contentWidth").toInt() - 48)),
                                  Q_ARG(QVariant, (double) system.getY() / 1000 * (mapRegion->property("contentHeight").toInt() - 48)));
    }
}

bool Navigation::isTravelableToSolarSystem(QString solarSystem) {
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
    ship.setFuel(ship.getFuel() - galaxy.getDistanceBetweenSolarSystems(origin, destination));
}
