#ifndef SHIP_H
#define SHIP_H

#include <QObject>

#include <QSharedDataPointer>

class ShipData;

class Ship : public QObject
{
public:
    Ship();
    Ship(const Ship &);
    Ship &operator=(const Ship &);
    ~Ship();

private:
    QSharedDataPointer<ShipData> data;
};

#endif // SHIP_H
