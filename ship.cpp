#include "ship.h"
#include <QSharedData>

class ShipData : public QSharedData {
public:
};

Ship::Ship() : data(new ShipData)
{
}

Ship::Ship(const Ship &rhs) : data(rhs.data)
{
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
