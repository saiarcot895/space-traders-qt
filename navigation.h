#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>
#include "galaxy.h"
#include "player.h"

#include <QVariant>

class Navigation : public QObject
{
    Q_OBJECT
public:
    explicit Navigation(QObject *rootObject = 0, QObject *parent = 0);

    void setRootObject(QObject* rootObject);
    void showNavigationPage();

    Q_INVOKABLE bool isTravelableToSolarSystem(QString solarSystem);
    Q_INVOKABLE void travelToSolarSystem(QString solarSystem);

private:
    QObject *rootObject;

    Galaxy galaxy = Galaxy::getInstance();
    Player player = Player::getInstance();

};

#endif // NAVIGATION_H
