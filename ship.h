#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include "ware.h"

class ShipData;

class Ship : public QObject
{
public:
    Ship();
    Ship(const Ship &);
    Ship &operator=(const Ship &);
    ~Ship();

    int getItemQuantity(Ware item) const;
    int getHealth() const;

    void setItemQuantity(Ware item, int quantity);
    void setHealth(int health);

private:
    QExplicitlySharedDataPointer<ShipData> data;
};

Q_DECLARE_TYPEINFO(Ship, Q_MOVABLE_TYPE);

#endif // SHIP_H
