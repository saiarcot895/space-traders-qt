#include "shipyard.h"

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
}
