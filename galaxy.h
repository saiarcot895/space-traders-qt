#ifndef GALAXY_H
#define GALAXY_H

#include <QObject>

#include <QExplicitlySharedDataPointer>
#include "solarsystem.h"

class GalaxyData;

class Galaxy : public QObject
{
public:
    Galaxy();
    Galaxy(const Galaxy &);
    Galaxy &operator=(const Galaxy &);
    ~Galaxy();

    const QList<SolarSystem> getSolarSystems() const;

private:
    QExplicitlySharedDataPointer<GalaxyData> data;
};

#endif // GALAXY_H
