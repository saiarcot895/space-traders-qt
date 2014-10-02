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

    QObject* navigationRectangle = rootObject->findChild<QObject*>("navigationScreen");

    for (int i = 0; i < galaxy.getSolarSystems().size(); i++) {
        const SolarSystem system = galaxy.getSolarSystems().at(i);
        QMetaObject::invokeMethod(navigationRectangle, "createPlanetButtons",
                                  Q_ARG(QVariant, system.getName()),
                                  Q_ARG(QVariant, (double) system.getX() / 1000 * navigationRectangle->property("width").toInt()),
                                  Q_ARG(QVariant, (double) system.getY() / 1000 * navigationRectangle->property("height").toInt()));
    }
}
