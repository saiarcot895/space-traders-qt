#include "ship.h"
#include <QSharedData>
#include <QMap>

class ShipData : public QSharedData {
public:
    Ship::ShipType shipType;
    QString name;
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
        data->maxHealth = 5000;
        data->maxFuel = 700;
        data->cargoCapacity = 5;
    } else if (type == Ship::Gnat) {
        data->shipType = Ship::Gnat;
        data->name = QStringLiteral("Gnat");
        data->maxHealth = 2000;
        data->maxFuel = 2500;
        data->cargoCapacity = 15;
    } else if (type == Ship::Firefly) {
        data->shipType = Ship::Firefly;
        data->name = QStringLiteral("Firefly");
        data->maxHealth = 5000;
        data->maxFuel = 4000;
        data->cargoCapacity = 20;
    } else if (type == Ship::Mosquito) {
        data->shipType = Ship::Mosquito;
        data->name = QStringLiteral("Mosquito");
        data->maxHealth = 5000;
        data->maxFuel = 5000;
        data->cargoCapacity = 15;
    } else if (type == Ship::Bumblebee) {
        data->shipType = Ship::Bumblebee;
        data->name = QStringLiteral("Bumblebee");
        data->maxHealth = 5000;
        data->maxFuel = 8000;
        data->cargoCapacity = 25;
    } else if (type == Ship::Beetle) {
        data->shipType = Ship::Beetle;
        data->name = QStringLiteral("Beetle");
        data->maxHealth = 3000;
        data->maxFuel = 6000;
        data->cargoCapacity = 40;
    } else if (type == Ship::Hornet) {
        data->shipType = Ship::Hornet;
        data->name = QStringLiteral("Hornet");
        data->maxHealth = 5000;
        data->maxFuel = 8000;
        data->cargoCapacity = 20;
    }

    data->health = data->maxHealth;
    data->fuel = data->maxFuel;
    data->numItemsInCargo = 0;
}

Ship::Ship(const Ship &rhs) : data(rhs.data)
{
}

QString Ship::getName() const {
    return data->name;
}

int Ship::getItemQuantity(Ware item) const {
    return data->cargo.value(item);
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
