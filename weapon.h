#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>

#include <QSharedDataPointer>

class WeaponData;

class Weapon : public QObject
{
public:
    enum WeaponType {
        Unknown = -1,
        Pulse,
        Beam,
        Missile,
        SIZE_WEAPON_TYPE
    };

    Weapon(WeaponType type = Unknown);
    Weapon(const Weapon &);
    Weapon &operator=(const Weapon &);
    ~Weapon();

    WeaponType getType() const;
    QString getName() const;
    int getPrice() const;
    int getShipDamage() const;
    int getShieldDamage() const;

private:
    QSharedDataPointer<WeaponData> data;
};

bool operator==(const Weapon& weapon1, const Weapon& weapon2);
uint qHash(const Weapon& weapon);

#endif // WEAPON_H
