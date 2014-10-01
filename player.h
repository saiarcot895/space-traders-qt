#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QExplicitlySharedDataPointer>
#include "solarsystem.h"

class PlayerData;

class Player : public QObject
{
public:
    Player(const Player &);
    Player &operator=(const Player &);
    ~Player();

    QString getName() const;
    double getX() const;
    double getY() const;
    int getCredits() const;
    int getPilotSkill() const;
    int getFighterSkill() const;
    int getTraderSkill() const;
    int getEngineerSkill() const;
    int getInvestorSkill() const;
    const SolarSystem getCurrentSystem() const;
    Planet getCurrentPlanet() const;

    void setName(QString name);
    void setX(double x);
    void setY(double y);
    void setCredits(int credits);
    void setPilotSkill(int pilotSkill);
    void setFighterSkill(int fighterSkill);
    void setTraderSkill(int traderSkill);
    void setEngineerSkill(int engineerSkill);
    void setInvestorSkill(int investorSkill);
    void setCurrentSystem(SolarSystem currentSystem);
    void setCurrentPlanet(Planet currentPlanet);

    static Player getInstance();

private:
    Player();

    QExplicitlySharedDataPointer<PlayerData> data;
    static Player instance;
};

#endif // PLAYER_H
