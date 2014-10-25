#include "ship.h"
#include <QSharedData>
#include <QMap>

class ShipData : public QSharedData {
public:
    QMap<Ware, int> items;
    int health;
};

Ship::Ship() : data(new ShipData)
{
}

Ship::Ship(const Ship &rhs) : data(rhs.data)
{
}

int Ship::getItemQuantity(Ware item) const{
    return data->items.value(item);
}

int Ship::getHealth() const {
    return data->health;
}

void Ship::setItemQuantity(Ware item, int quantity) {
    data->items.insert(item, quantity);
}

void Ship::setHealth(int health) {
    data->health = health;
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
