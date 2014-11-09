#include "navigation.h"
#include <QVariant>
#include <QtMath>

Navigation::Navigation(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject)
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
                                  Q_ARG(QVariant, (double) system.getX() / 1000 * (mapRegion->property("contentWidth").toInt() - 32)),
                                  Q_ARG(QVariant, (double) system.getY() / 1000 * (mapRegion->property("contentHeight").toInt() - 32)));
    }
}

bool Navigation::isTravelableToSolarSystem(QString solarSystem) {
    SolarSystem origin = Player::getInstance().getCurrentSystem();
    SolarSystem destination = Galaxy::getInstance().getSolarSystem(solarSystem);
    Ship ship = Player::getInstance().getShip();

    return Galaxy::getInstance().getDistanceBetweenSolarSystems(origin, destination) < ship.getFuel();
}

void Navigation::travelToSolarSystem(QString solarSystem) {
    SolarSystem origin = Player::getInstance().getCurrentSystem();
    SolarSystem destination = Galaxy::getInstance().getSolarSystem(solarSystem);
    Ship ship = Player::getInstance().getShip();

    player.setCurrentSystem(Galaxy::getInstance().getSolarSystem(solarSystem));
    ship.setFuel(ship.getFuel() - Galaxy::getInstance().getDistanceBetweenSolarSystems(origin, destination));
}
