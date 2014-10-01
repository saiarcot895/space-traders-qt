#ifndef GALAXY_H
#define GALAXY_H

#include <QObject>

#include <QExplicitlySharedDataPointer>
#include "solarsystem.h"

class GalaxyData;

class Galaxy : public QObject
{
public:
    Galaxy(const Galaxy &);
    Galaxy &operator=(const Galaxy &);
    ~Galaxy();

    const QList<SolarSystem> getSolarSystems() const;

    static Galaxy getInstance();

private:
    Galaxy();

    QExplicitlySharedDataPointer<GalaxyData> data;

    static Galaxy instance;
};

#endif // GALAXY_H
