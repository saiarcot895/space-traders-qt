#include "shipyard.h"
#include "player.h"
#include "ship.h"

#include <QVariant>

Shipyard::Shipyard(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject)
{
}

void Shipyard::setRootObject(QObject *rootObject) {
    this->rootObject = rootObject;
}

void Shipyard::showShipyard() {
    Q_ASSERT(rootObject);
    rootObject->findChild<QObject*>("pageLoader")->setProperty("source", QStringLiteral("qrc:///shipyard.qml"));

    QObject* shipyardShips = rootObject->findChild<QObject*>("shipyardShips");

    Ship currentShip = Player::getInstance().getShip();

    QMetaObject::invokeMethod(shipyardShips, "setCurrentShip",
                              Q_ARG(QVariant, currentShip.getName()),
                              Q_ARG(QVariant, currentShip.getCargoCapacity()),
                              Q_ARG(QVariant, currentShip.getMaxHealth()),
                              Q_ARG(QVariant, currentShip.getMaxFuel()));

    for (int i = 0; i < Ship::SIZE_SHIP_TYPE; i++) {
        Ship ship(static_cast<Ship::ShipType>(i));
        QMetaObject::invokeMethod(shipyardShips, "createShip",
                                  Q_ARG(QVariant, ship.getName()),
                                  Q_ARG(QVariant, ship.getCargoCapacity()),
                                  Q_ARG(QVariant, ship.getMaxHealth()),
                                  Q_ARG(QVariant, ship.getMaxFuel()));
    }
}
