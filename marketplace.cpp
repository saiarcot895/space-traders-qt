#include "marketplace.h"

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
}
