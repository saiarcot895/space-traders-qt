#include "solarsystem.h"
#include <QSharedData>

class SolarSystemData : public QSharedData {
public:
    QString name;
    QList<Planet> planets;
    QColor color;
    double x;
    double y;
};

SolarSystem::SolarSystem(QString name) : data(new SolarSystemData)
{
    data->name = name;
    data->x = qrand() % 1000;
    data->y = qrand() % 1000;
    data->color = QColor(qrand() % 256, qrand() % 256, qrand() % 256, 48);
    for (int i = 0; i < 1; i++) {
        data->planets.append(Planet(data->name, data->x, data->y));
    }
}

SolarSystem::SolarSystem(QString name, double x, double y, QList<Planet> planets)
    : data(new SolarSystemData)
{
    data->name = name;
    data->x = x;
    data->y = y;
    data->planets.append(planets);
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

QColor SolarSystem::getColor() const {
    return data->color;
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

bool operator==(const SolarSystem solarSystem1, const SolarSystem solarSystem2) {
    return solarSystem1.getName() == solarSystem2.getName()
            && solarSystem1.getX() == solarSystem2.getX()
            && solarSystem1.getY() == solarSystem2.getY();
}

QDataStream& operator<<(QDataStream& stream, const SolarSystem solarSystem) {
    stream << solarSystem.getName();
    stream << solarSystem.getX();
    stream << solarSystem.getY();
    stream << solarSystem.getPlanets();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, SolarSystem& solarSystem) {
    QString name;
    double x;
    double y;
    QList<Planet> planets;

    stream >> name;
    stream >> x;
    stream >> y;
    stream >> planets;

    solarSystem = SolarSystem(name, x, y, planets);

    return stream;
}
