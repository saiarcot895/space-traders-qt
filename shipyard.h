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

private:
    QObject* rootObject;

};

#endif // SHIPYARD_H
