#include "ship.h"
#include <QSharedData>
#include <QMap>

class ShipData : public QSharedData {
public:
    Ship::ShipType shipType;
    QString name;
    int cost;
    int health;
    int maxHealth;
    int fuel;
    int maxFuel;
    QMap<Ware, int> cargo;
    int numItemsInCargo;
    int cargoCapacity;
};

Ship::Ship(ShipType type) : data(new ShipData)
{
    if (type == Ship::Flea) {
        data->shipType = Ship::Flea;
        data->name = QStringLiteral("Flea");
        data->cost = 100;
        data->maxHealth = 5000;
        data->maxFuel = 700;
        data->cargoCapacity = 5;
    } else if (type == Ship::Gnat) {
        data->shipType = Ship::Gnat;
        data->name = QStringLiteral("Gnat");
        data->cost = 500;
        data->maxHealth = 2000;
        data->maxFuel = 2500;
        data->cargoCapacity = 15;
    } else if (type == Ship::Firefly) {
        data->shipType = Ship::Firefly;
        data->name = QStringLiteral("Firefly");
        data->cost = 1000;
        data->maxHealth = 5000;
        data->maxFuel = 4000;
        data->cargoCapacity = 20;
    } else if (type == Ship::Mosquito) {
        data->shipType = Ship::Mosquito;
        data->name = QStringLiteral("Mosquito");
        data->cost = 2500;
        data->maxHealth = 5000;
        data->maxFuel = 5000;
        data->cargoCapacity = 15;
    } else if (type == Ship::Bumblebee) {
        data->shipType = Ship::Bumblebee;
        data->name = QStringLiteral("Bumblebee");
        data->cost = 6000;
        data->maxHealth = 5000;
        data->maxFuel = 8000;
        data->cargoCapacity = 25;
    } else if (type == Ship::Beetle) {
        data->shipType = Ship::Beetle;
        data->name = QStringLiteral("Beetle");
        data->cost = 12000;
        data->maxHealth = 3000;
        data->maxFuel = 6000;
        data->cargoCapacity = 40;
    } else if (type == Ship::Hornet) {
        data->shipType = Ship::Hornet;
        data->name = QStringLiteral("Hornet");
        data->cost = 18000;
        data->maxHealth = 5000;
        data->maxFuel = 8000;
        data->cargoCapacity = 20;
    }

    data->health = data->maxHealth;
    data->fuel = data->maxFuel;
    data->numItemsInCargo = 0;
}

Ship::Ship(const Ship &rhs) :
    QObject(),
    data(rhs.data)
{
}

Ship::ShipType Ship::getType() const {
    return data->shipType;
}

QString Ship::getName() const {
    return data->name;
}

int Ship::getCost() const {
    return data->cost;
}

int Ship::getItemQuantity(Ware item) const {
    return data->cargo.value(item);
}

QMap<Ware, int> Ship::getItems() const {
    return data->cargo;
}

int Ship::getNumItemsInCargo() const {
    return data->numItemsInCargo;
}

int Ship::getCargoCapacity() const {
    return data->cargoCapacity;
}

int Ship::getHealth() const {
    return data->health;
}

int Ship::getMaxHealth() const {
    return data->maxHealth;
}

int Ship::getFuel() const {
    return data->fuel;
}

int Ship::getMaxFuel() const {
    return data->maxFuel;
}

void Ship::setItemQuantity(Ware item, int quantity) {
    int currentQuantity = getItemQuantity(item);
    data->cargo.insert(item, quantity);
    data->numItemsInCargo += quantity - currentQuantity;
}

void Ship::setHealth(int health) {
    data->health = health;
}

void Ship::setFuel(int fuel) {
    data->fuel = fuel;
}

Ship &Ship::operator=(const Ship &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Ship::~Ship()
{
}

QDataStream& operator<<(QDataStream& stream, const Ship ship) {
    stream << ship.getType();
    stream << ship.getItems();
    stream << ship.getHealth();
    stream << ship.getFuel();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Ship& ship) {
    int shipType;
    QMap<Ware, int> items;
    int health;
    int fuel;

    stream >> shipType;
    stream >> items;
    stream >> health;
    stream >> fuel;

    ship = Ship(static_cast<Ship::ShipType>(shipType));
    for (int i = 0; i < Ware::SIZE_GOOD; i++) {
        Ware ware(static_cast<Ware::Good>(i));
        ship.setItemQuantity(ware, items.value(ware));
    }
    ship.setHealth(health);
    ship.setFuel(fuel);

    return stream;
}
