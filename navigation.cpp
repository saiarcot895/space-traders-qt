#include "navigation.h"
#include <QVariant>

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

    for (int i = 0; i < galaxy.getSolarSystems().size(); i++) {
        const SolarSystem system = galaxy.getSolarSystems().at(i);
        QMetaObject::invokeMethod(rootObject->findChild<QObject*>("navigationScreen"), "createPlanetButtons",
                                  Q_ARG(QVariant, system.getName()),
                                  Q_ARG(QVariant, system.getX()),
                                  Q_ARG(QVariant, system.getY()));
    }
}
