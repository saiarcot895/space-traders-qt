#ifndef SHIPYARD_H
#define SHIPYARD_H

#include <QObject>

class Shipyard : public QObject
{
    Q_OBJECT
public:
    explicit Shipyard(QObject *rootObject = 0, QObject *parent = 0);

    void setRootObject(QObject *rootObject);
    void showShipyard();

    Q_INVOKABLE void instantiateShipTab();
    Q_INVOKABLE void instantiateGadgetsTab();

    Q_INVOKABLE void buyShip(int index);
    Q_INVOKABLE void buyGadget(int index);
    Q_INVOKABLE void sellGadget(int index);

private:
    QObject* rootObject;

};

#endif // SHIPYARD_H
