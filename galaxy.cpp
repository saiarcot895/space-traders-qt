#include "galaxy.h"
#include <QMap>
#include <QSharedData>
#include <QTime>

Galaxy Galaxy::instance = Galaxy();

class GalaxyData : public QSharedData {
public:
    QMap<QString, SolarSystem> solarSystems;
};

Galaxy::Galaxy() : data(new GalaxyData)
{
    qsrand(QTime::currentTime().msec());

    data->solarSystems.insert("Earth616", SolarSystem("Earth616"));
    data->solarSystems.insert("Utopia", SolarSystem("Utopia"));
    data->solarSystems.insert("Omega", SolarSystem("Omega"));
    data->solarSystems.insert("Tantalos", SolarSystem("Tantalos"));
    data->solarSystems.insert("Carzon", SolarSystem("Carzon"));
    data->solarSystems.insert("Exo", SolarSystem("Exo"));
    data->solarSystems.insert("Destiny", SolarSystem("Destiny"));
    data->solarSystems.insert("Frolix", SolarSystem("Frolix"));
}

Galaxy::Galaxy(const Galaxy &rhs) : data(rhs.data)
{
}

const QList<SolarSystem> Galaxy::getSolarSystems() const {
    return data->solarSystems.values();
}

const SolarSystem Galaxy::getSolarSystem(QString name) const {
    return data->solarSystems.value(name);
}

Galaxy Galaxy::getInstance() {
    return instance;
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
