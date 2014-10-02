#include "player.h"
#include "galaxy.h"
#include <QSharedData>

Player Player::instance = Player();

class PlayerData : public QSharedData {
public:
    QString name;
    double x;
    double y;
    int credits;
    int pilotSkill;
    int fighterSkill;
    int traderSkill;
    int engineerSkill;
    int investorSkill;
    SolarSystem currentSystem;
    Planet currentPlanet;
};

Player::Player() : data(new PlayerData)
{
    data->currentSystem = Galaxy::getInstance().getSolarSystem("Earth616");
    data->currentPlanet = data->currentSystem.getPlanets().at(0);
}

Player::Player(const Player &rhs) : data(rhs.data)
{
}

QString Player::getName() const {
    return data->name;
}

double Player::getX() const {
    return data->x;
}

double Player::getY() const {
    return data->y;
}

int Player::getCredits() const {
    return data->credits;
}

int Player::getPilotSkill() const {
    return data->pilotSkill;
}

int Player::getFighterSkill() const {
    return data->fighterSkill;
}

int Player::getTraderSkill() const {
    return data->traderSkill;
}

int Player::getEngineerSkill() const {
    return data->engineerSkill;
}

int Player::getInvestorSkill() const {
    return data->investorSkill;
}

const SolarSystem Player::getCurrentSystem() const {
    return data->currentSystem;
}

Planet Player::getCurrentPlanet() const {
    return data->currentPlanet;
}

void Player::setName(QString name) {
    data->name = name;
}

void Player::setX(double x) {
    data->x = x;
}

void Player::setY(double y) {
    data->y = y;
}

void Player::setCredits(int credits) {
    data->credits = credits;
}

void Player::setPilotSkill(int pilotSkill) {
    data->pilotSkill = pilotSkill;
}

void Player::setFighterSkill(int fighterSkill) {
    data->fighterSkill = fighterSkill;
}

void Player::setTraderSkill(int traderSkill) {
    data->traderSkill = traderSkill;
}

void Player::setEngineerSkill(int engineerSkill) {
    data->engineerSkill = engineerSkill;
}

void Player::setInvestorSkill(int investorSkill) {
    data->investorSkill = investorSkill;
}

void Player::setCurrentSystem(SolarSystem currentSystem) {
    data->currentSystem = currentSystem;
}

void Player::setCurrentPlanet(Planet currentPlanet) {
    data->currentPlanet = currentPlanet;
}

Player Player::getInstance() {
    return Player::instance;
}

Player &Player::operator=(const Player &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Player::~Player()
{
}
