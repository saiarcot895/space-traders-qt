#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include "planet.h"

class SolarSystemData;

class SolarSystem : public QObject
{
public:
    SolarSystem();
    SolarSystem(QString name);
    SolarSystem(const SolarSystem &);
    SolarSystem &operator=(const SolarSystem &);
    ~SolarSystem();

    QString getName() const;
    QList<Planet> getPlanets() const;
    double getX() const;
    double getY() const;

private:
    QExplicitlySharedDataPointer<SolarSystemData> data;
};

#endif // SOLARSYSTEM_H
