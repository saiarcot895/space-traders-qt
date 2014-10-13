#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include <QMap>
#include "ware.h"

class PlanetData;

class Planet : public QObject
{
public:
    Planet();
    Planet(QString name, double x, double y);
    Planet(const Planet &);
    Planet &operator=(const Planet &);
    ~Planet();

    enum TechLevel {
        UnknownLevel = -1,
        PreAgriculture,
        Agriculture,
        Medieval,
        Renaissance,
        EarlyIndustrial,
        Industrial,
        PostIndustrial,
        HiTech,

        SIZE_LEVEL // DO NOT MOVE OR REMOVE
    };

    enum ResourceTypes {
        UnknownResource = -1,
        NoSpecializedResources,
        MineralRich,
        MineralPoor,
        Desert,
        LotsOfWater,
        RichSoil,
        PoorSoil,
        RichFauna,
        Lifeless,
        WeirdMushrooms,
        LotsOfHerbs,
        Artistic,
        Warlike,

        SIZE_RESOURCE // DO NOT MOVE OR REMOVE
    };

    QString getName() const;
    double getX() const;
    double getY() const;
    double getRadius() const;
    TechLevel getTechLevel() const;
    ResourceTypes getResourceType() const;
    int getItemQuantity(Ware ware) const;

private:
    void produceWares();

    QExplicitlySharedDataPointer<PlanetData> data;
};

#endif // PLANET_H
