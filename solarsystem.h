#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <QObject>
#include <QColor>
#include <QDataStream>
#include <QExplicitlySharedDataPointer>
#include "planet.h"

class SolarSystemData;

class SolarSystem : public QObject
{
public:
    SolarSystem(QString name = QStringLiteral(""));
    SolarSystem(QString name, double x, double y, QList<Planet> planets);
    SolarSystem(const SolarSystem &);
    SolarSystem &operator=(const SolarSystem &);
    ~SolarSystem();

    QString getName() const;
    QList<Planet> getPlanets() const;
    double getX() const;
    double getY() const;
    QColor getColor() const;

private:
    QExplicitlySharedDataPointer<SolarSystemData> data;
};

Q_DECLARE_TYPEINFO(SolarSystem, Q_MOVABLE_TYPE);

QDataStream& operator<<(QDataStream& stream, const SolarSystem solarSystem);
QDataStream& operator>>(QDataStream& stream, SolarSystem& solarSystem);

#endif // SOLARSYSTEM_H
