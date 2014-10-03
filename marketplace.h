#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <QObject>

class Marketplace : public QObject
{
    Q_OBJECT
public:
    explicit Marketplace(QObject *rootObject = 0, QObject *parent = 0);

    void setRootObject(QObject *rootObject);
    void showMarketplace();

private:
    QObject* rootObject;

};

#endif // MARKETPLACE_H
