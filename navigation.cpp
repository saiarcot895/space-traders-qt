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
}
