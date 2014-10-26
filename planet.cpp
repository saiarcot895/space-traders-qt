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
    QMap<Ware, int> items;
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
    produceWares();
}

Planet::Planet(const Planet &rhs) : data(rhs.data)
{
}

void Planet::produceWares() {
    for (int i = 0; i < Ware::SIZE_GOOD; i++) {
        Ware ware(static_cast<Ware::Good>(i));
        if (data->techLevel < ware.getMinimumTechLevelToProduce()) {
            data->items.insert(ware, 0);
        } else {
            data->items.insert(ware, 1 + qAbs(ware.getTechLevelProduction() - data->techLevel));
        }
    }
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

int Planet::getItemQuantity(Ware ware) const {
    return data->items.value(ware);
}

void Planet::setItemQuantity(Ware ware, int newQuantity) {
    data->items.insert(ware, newQuantity);
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

QDataStream& operator<<(QDataStream& stream, const Planet planet) {
    stream << planet.getName();
    stream << planet.getX();
    stream << planet.getY();
    stream << planet.getRadius();
    stream << planet.getTechLevel();
    stream << planet.getResourceType();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Planet& planet) {
    QString name;
    double x;
    double y;
    double radius;
    int techLevelInt;
    int resourceTypeInt;

    stream >> name;
    stream >> x;
    stream >> y;
    stream >> radius;
    stream >> techLevelInt;
    stream >> resourceTypeInt;

    planet = Planet(name, x, y);
}
