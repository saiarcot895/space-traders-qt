#include "planet.h"
#include <QSharedData>

class PlanetData : public QSharedData {
public:
    QString name;
    double radius;
    QColor color;
    Planet::TechLevel techLevel = Planet::UnknownLevel;
    Planet::ResourceTypes resourceTypes = Planet::UnknownResource;
    QMap<Ware, int> items;
};

Planet::Planet() :
    Planet("")
{
}

Planet::Planet(QString name) : data(new PlanetData)
{
    data->name = name;
    data->radius = qrand() % 200 + 50;
    data->color = QColor(qrand() % 256, qrand() % 256, qrand() % 256, 127);
    data->techLevel = static_cast<Planet::TechLevel>(qrand() % Planet::SIZE_LEVEL);
    data->resourceTypes = static_cast<Planet::ResourceTypes>(qrand() % Planet::SIZE_RESOURCE);
    produceWares();
}

Planet::Planet(QString name, double radius, TechLevel techLevel, ResourceTypes resourceTypes) :
    data(new PlanetData) {
    data->name = name;
    data->radius = radius;
    data->color = QColor(qrand() % 256, qrand() % 256, qrand() % 256, 127);
    data->techLevel = techLevel;
    data->resourceTypes = resourceTypes;
}

Planet::Planet(const Planet &rhs) :
    QObject(),
    data(rhs.data)
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
double Planet::getRadius() const {
    return data->radius;
}

QColor Planet::getColor() const {
    return data->color;
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

bool operator==(const Planet planet1, const Planet planet2) {
    return planet1.getName() == planet2.getName()
            && planet1.getColor() == planet2.getColor()
            && planet1.getRadius() == planet2.getRadius();
}

QDataStream& operator<<(QDataStream& stream, const Planet planet) {
    stream << planet.getName();
    stream << planet.getRadius();
    stream << planet.getTechLevel();
    stream << planet.getResourceType();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Planet& planet) {
    QString name;
    double radius;
    int techLevelInt;
    int resourceTypeInt;

    stream >> name;
    stream >> radius;
    stream >> techLevelInt;
    stream >> resourceTypeInt;

    planet = Planet(name, radius, static_cast<Planet::TechLevel>(techLevelInt), static_cast<Planet::ResourceTypes>(resourceTypeInt));

    return stream;
}
