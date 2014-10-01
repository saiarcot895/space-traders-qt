#include "galaxy.h"
#include <QSharedData>

class GalaxyData : public QSharedData {
public:
    QList<SolarSystem> solarSystems;
};

Galaxy::Galaxy() : data(new GalaxyData)
{
    data->solarSystems.append(SolarSystem("Earth616"));
    data->solarSystems.append(SolarSystem("Utopia"));
    data->solarSystems.append(SolarSystem("Omega"));
    data->solarSystems.append(SolarSystem("Tantalos"));
    data->solarSystems.append(SolarSystem("Carzon"));
    data->solarSystems.append(SolarSystem("Exo"));
    data->solarSystems.append(SolarSystem("Destiny"));
    data->solarSystems.append(SolarSystem("Frolix"));
}

Galaxy::Galaxy(const Galaxy &rhs) : data(rhs.data)
{
}

const QList<SolarSystem> Galaxy::getSolarSystems() const {
    return data->solarSystems;
}

Galaxy &Galaxy::operator=(const Galaxy &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Galaxy::~Galaxy()
{
}
