#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include <QList>
#include <QMap>
#include <QDataStream>
#include <QSet>
#include "ware.h"
#include "gadget.h"

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
        //Grasshopper,
        //Termite,
        //Wasp,

        SIZE_SHIP_TYPE
    };

    Ship(ShipType type = UnknownShip);
    Ship(const Ship &);
    Ship &operator=(const Ship &);
    ~Ship();

    ShipType getType() const;
    QString getName() const;
    int getCost() const;
    int getItemQuantity(Ware item) const;
    QMap<Ware, int> getItems() const;
    int getNumItemsInCargo() const;
    int getCargoCapacity() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getFuel() const;
    int getMaxFuel() const;
    QSet<Gadget> getGadgets() const;
    int getGadgetCapacity() const;

    void setItemQuantity(Ware item, int quantity);
    void setHealth(int health);
    void setFuel(int fuel);
    bool addGadget(Gadget gadget);
    bool removeGadget(Gadget gadget);

private:
    QExplicitlySharedDataPointer<ShipData> data;
};

Q_DECLARE_TYPEINFO(Ship, Q_MOVABLE_TYPE);

QDataStream& operator<<(QDataStream& stream, const Ship ship);
QDataStream& operator>>(QDataStream& stream, Ship& ship);

#endif // SHIP_H
