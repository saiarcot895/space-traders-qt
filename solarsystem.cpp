#include "solarsystem.h"
#include <QSharedData>

class SolarSystemData : public QSharedData {
public:
    QString name;
    QList<Planet> planets;
    double x;
    double y;
};

SolarSystem::SolarSystem(QString name) : data(new SolarSystemData)
{
    data->name = name;
    data->x = qrand() % 500;
    data->y = qrand() % 500;
    for (int i = 0; i < 1; i++) {
        data->planets.append(Planet(data->name, data->x, data->y));
    }
}

SolarSystem::SolarSystem(const SolarSystem &rhs) : data(rhs.data)
{
}

QString SolarSystem::getName() const {
    return data->name;
}

QList<Planet> SolarSystem::getPlanets() const {
    return data->planets;
}

double SolarSystem::getX() const {
    return data->x;
}

double SolarSystem::getY() const {
    return data->y;
}

SolarSystem &SolarSystem::operator=(const SolarSystem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

SolarSystem::~SolarSystem()
{
}
