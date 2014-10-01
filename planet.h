#ifndef PLANET_H
#define PLANET_H

#include <QObject>

#include <QExplicitlySharedDataPointer>

class PlanetData;

class Planet : public QObject
{
public:
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

        SIZE_LEVEL
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

        SIZE_RESOURCE
    };

    QString getName() const;
    double getX() const;
    double getY() const;
    double getRadius() const;
    TechLevel getTechLevel() const;
    ResourceTypes getResourceType() const;

private:
    QExplicitlySharedDataPointer<PlanetData> data;
};

#endif // PLANET_H
