#ifndef GALAXY_H
#define GALAXY_H

#include <QObject>

#include <QExplicitlySharedDataPointer>
#include "solarsystem.h"

class GalaxyData;

class Galaxy : public QObject
{
public:
    Galaxy(const QList<SolarSystem> solarSystems);
    Galaxy(const Galaxy &);
    Galaxy &operator=(const Galaxy &);
    ~Galaxy();

    const QList<SolarSystem> getSolarSystems() const;
    const SolarSystem getSolarSystem(QString name) const;
    double getDistanceBetweenSolarSystems(const SolarSystem origin, const SolarSystem destination) const;

    static Galaxy getInstance();

private:
    Galaxy();

    QExplicitlySharedDataPointer<GalaxyData> data;

    static Galaxy instance;
};

Q_DECLARE_TYPEINFO(Galaxy, Q_MOVABLE_TYPE);

QDataStream& operator<<(QDataStream& stream, const Galaxy galaxy);
QDataStream& operator>>(QDataStream& stream, Galaxy& galaxy);

#endif // GALAXY_H
