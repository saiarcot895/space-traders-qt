#include "marketplace.h"
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

    QMetaObject::invokeMethod(marketplaceScreen, "createProduct",
                              Q_ARG(QVariant, "Herbs"),
                              Q_ARG(QVariant, 300),
                              Q_ARG(QVariant, 15),
                              Q_ARG(QVariant, 20));

    QMetaObject::invokeMethod(marketplaceScreen, "createProduct",
                              Q_ARG(QVariant, "Oil"),
                              Q_ARG(QVariant, 60),
                              Q_ARG(QVariant, 150),
                              Q_ARG(QVariant, 110));

    QMetaObject::invokeMethod(marketplaceScreen, "createProduct",
                              Q_ARG(QVariant, "Tomato"),
                              Q_ARG(QVariant, 60),
                              Q_ARG(QVariant, 0),
                              Q_ARG(QVariant, 110));
}
