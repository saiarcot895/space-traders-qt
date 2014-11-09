#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include <QList>
#include "ware.h"

class ShipData;

class Ship : public QObject
{
public:

    enum ShipType {
        UnknownShip = -1,
        Flea,
        Gnat,
        Firefly,
        Mosquito,
        Bumblebee,
        Beetle,
        Hornet,
        Grasshopper,
        Termite,
        Wasp
    };

    Ship(ShipType type = UnknownShip);
    Ship(const Ship &);
    Ship &operator=(const Ship &);
    ~Ship();

    int getItemQuantity(Ware item) const;
    int getNumItemsInCargo() const;
    int getCargoCapacity() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getFuel() const;
    int getMaxFuel() const;

    void setItemQuantity(Ware item, int quantity);
    void setHealth(int health);
    void setFuel(int fuel);

private:
    QExplicitlySharedDataPointer<ShipData> data;
};

Q_DECLARE_TYPEINFO(Ship, Q_MOVABLE_TYPE);

#endif // SHIP_H
