#include "planet.h"
#include <QSharedData>

class PlanetData : public QSharedData {
public:
    QString name;
    double x;
    double y;
    double radius;
    Planet::TechLevel techLevel = Planet::UnknownLevel;
    Planet::ResourceTypes resourceTypes = Planet::UnknownResource;
    //QMap<Item, int> items;
};

Planet::Planet() :
    Planet("", 0, 0)
{
}

Planet::Planet(QString name, double x, double y) : data(new PlanetData)
{
    data->name = name;
    data->x = x;
    data->y = y;
    data->radius = qrand() % 250;
    data->techLevel = static_cast<Planet::TechLevel>(qrand() % Planet::SIZE_LEVEL);
    data->resourceTypes = static_cast<Planet::ResourceTypes>(qrand() % Planet::SIZE_RESOURCE);
}

Planet::Planet(const Planet &rhs) : data(rhs.data)
{
}

QString Planet::getName() const {
    return data->name;
}

double Planet::getX() const {
    return data->x;
}

double Planet::getY() const {
    return data->y;
}

double Planet::getRadius() const {
    return data->radius;
}

Planet::TechLevel Planet::getTechLevel() const {
    return data->techLevel;
}

Planet::ResourceTypes Planet::getResourceType() const {
    return data->resourceTypes;
}

Planet &Planet::operator=(const Planet &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Planet::~Planet()
{
}
