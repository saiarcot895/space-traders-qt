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

    Player player = Player::getInstance();
    QObject* shipyardShips = rootObject->findChild<QObject*>("shipyardShips");
    shipyardShips->setProperty("creditsAvailable", player.getCredits());

    Ship currentShip = player.getShip();

    QMetaObject::invokeMethod(shipyardShips, "setCurrentShip",
                              Q_ARG(QVariant, currentShip.getName()),
                              Q_ARG(QVariant, currentShip.getCargoCapacity()),
                              Q_ARG(QVariant, currentShip.getMaxHealth()),
                              Q_ARG(QVariant, currentShip.getMaxFuel()),
                              Q_ARG(QVariant, currentShip.getCost()));

    for (int i = 0; i < Ship::SIZE_SHIP_TYPE; i++) {
        Ship ship(static_cast<Ship::ShipType>(i));
        QMetaObject::invokeMethod(shipyardShips, "createShip",
                                  Q_ARG(QVariant, ship.getName()),
                                  Q_ARG(QVariant, ship.getCargoCapacity()),
                                  Q_ARG(QVariant, ship.getMaxHealth()),
                                  Q_ARG(QVariant, ship.getMaxFuel()),
                                  Q_ARG(QVariant, ship.getCost()));
    }
}

void Shipyard::buyShip(int index) {
    Ship::ShipType shipType = static_cast<Ship::ShipType>(index);
    Ship newShip(shipType);

    QObject* shipyardShips = rootObject->findChild<QObject*>("shipyardShips");
    Player player = Player::getInstance();

    if (player.getCredits() + player.getShip().getCost() < newShip.getCost()) {
        QMetaObject::invokeMethod(shipyardShips, "showMessage",
                                  Q_ARG(QVariant, QStringLiteral("Not enough credits!")));
        return;
    }

    player.setCredits(player.getCredits() + player.getShip().getCost() - newShip.getCost());
    player.setShip(newShip);
    shipyardShips->setProperty("creditsAvailable", player.getCredits());

    QMetaObject::invokeMethod(shipyardShips, "setCurrentShip",
                              Q_ARG(QVariant, newShip.getName()),
                              Q_ARG(QVariant, newShip.getCargoCapacity()),
                              Q_ARG(QVariant, newShip.getMaxHealth()),
                              Q_ARG(QVariant, newShip.getMaxFuel()),
                              Q_ARG(QVariant, newShip.getCost()));
}
