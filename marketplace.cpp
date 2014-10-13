#include "marketplace.h"
#include "player.h"
#include <QVariant>

Marketplace::Marketplace(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject)
{
}

void Marketplace::setRootObject(QObject *rootObject) {
    this->rootObject = rootObject;
}

void Marketplace::showMarketplace() {
    Q_ASSERT(rootObject);
    rootObject->findChild<QObject*>("pageLoader")->setProperty("source", QStringLiteral("qrc:///marketplace.qml"));

    QObject* marketplaceScreen = rootObject->findChild<QObject*>("marketplaceScreen");

    Player player = Player::getInstance();
    Planet planet = player.getCurrentPlanet();

    for (int i = 0; i < Ware::SIZE_GOOD; i++) {
        Ware::Good good = static_cast<Ware::Good>(i);
        Ware ware(good);
        QMetaObject::invokeMethod(marketplaceScreen, "createProduct",
                                  Q_ARG(QVariant, ware.getName()),
                                  Q_ARG(QVariant, ware.getBasePrice()),
                                  Q_ARG(QVariant, planet.getItemQuantity(ware)),
                                  Q_ARG(QVariant, 0));
    }
}
