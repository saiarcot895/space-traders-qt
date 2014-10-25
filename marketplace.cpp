#include "marketplace.h"
#include "player.h"
#include <QVariant>

Marketplace::Marketplace(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject),
    creditChanges(0)
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

void Marketplace::buyItem(int index) {
    QVariant itemModelVariant;

    QObject* marketplaceScreen = rootObject->findChild<QObject*>("marketplaceScreen");
    QMetaObject::invokeMethod(marketplaceScreen, "getProduct",
                              Q_RETURN_ARG(QVariant, itemModelVariant),
                              Q_ARG(QVariant, index));

    QObject* itemModel = itemModelVariant.value<QObject*>();
    int price = itemModel->property("price").toInt();

    if (Player::getInstance().getCredits() + creditChanges < price) {
        return;
    }

    creditChanges -= price;

    int planetQuantity = itemModel->property("planetQuantity").toInt();
    itemModel->setProperty("planetQuantity", planetQuantity - 1);

    int shipQuantity = itemModel->property("shipQuantity").toInt();
    itemModel->setProperty("shipQuantity", shipQuantity + 1);

    QMetaObject::invokeMethod(marketplaceScreen, "setProduct",
                              Q_ARG(QVariant, index),
                              Q_ARG(QVariant, itemModelVariant),
                              Q_ARG(QVariant, true));
}

void Marketplace::sellItem(int index) {
    QVariant itemModelVariant;

    QObject* marketplaceScreen = rootObject->findChild<QObject*>("marketplaceScreen");
    QMetaObject::invokeMethod(marketplaceScreen, "getProduct",
                              Q_RETURN_ARG(QVariant, itemModelVariant),
                              Q_ARG(QVariant, index));

    QObject* itemModel = itemModelVariant.value<QObject*>();
    int price = itemModel->property("price").toInt();

    creditChanges += price;

    int planetQuantity = itemModel->property("planetQuantity").toInt();
    itemModel->setProperty("planetQuantity", planetQuantity + 1);

    int shipQuantity = itemModel->property("shipQuantity").toInt();
    itemModel->setProperty("shipQuantity", shipQuantity - 1);

    QMetaObject::invokeMethod(marketplaceScreen, "setProduct",
                              Q_ARG(QVariant, index),
                              Q_ARG(QVariant, itemModelVariant),
                              Q_ARG(QVariant, true));
}

void Marketplace::saveChanges() {
    Player player = Player::getInstance();
    Planet planet = player.getCurrentPlanet();
    QObject* marketplaceScreen = rootObject->findChild<QObject*>("marketplaceScreen");

    for (int i = 0; i < Ware::SIZE_GOOD; i++) {
        Ware::Good good = static_cast<Ware::Good>(i);
        Ware ware(good);

        QVariant itemModelVariant;
        QMetaObject::invokeMethod(marketplaceScreen, "getProduct",
                                  Q_RETURN_ARG(QVariant, itemModelVariant),
                                  Q_ARG(QVariant, i));
    }
}
