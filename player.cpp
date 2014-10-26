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
    int remainingSkill;
    int pilotSkill;
    int fighterSkill;
    int traderSkill;
    int engineerSkill;
    int investorSkill;
    SolarSystem currentSystem;
    Planet currentPlanet;
    Ship ship;
};

Player::Player() : data(new PlayerData)
{
    data->currentSystem = Galaxy::getInstance().getSolarSystem("Earth616");
    data->currentPlanet = data->currentSystem.getPlanets().at(0);
    data->credits = 750;
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

int Player::getRemainingSkill() const {
    return data->remainingSkill;
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

Ship Player::getShip() const {
    return data->ship;
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

void Player::setRemainingSkill(int remainingSkill) {
    data->remainingSkill = remainingSkill;
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

void Player::setShip(Ship ship) {
    data->ship = ship;
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

QDataStream& operator<<(QDataStream& stream, const Player player) {
    stream << player.getName();
    stream << player.getX();
    stream << player.getY();
    stream << player.getCredits();
    stream << player.getRemainingSkill();
    stream << player.getPilotSkill();
    stream << player.getFighterSkill();
    stream << player.getTraderSkill();
    stream << player.getEngineerSkill();
    stream << player.getInvestorSkill();
    stream << player.getCurrentSystem().getName();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Player player) {
    QString name;
    double x;
    double y;
    int credits;
    int remainingSkill;
    int pilotSkill;
    int fighterSkill;
    int traderSkill;
    int engineerSkill;
    int investorSkill;
    QString systemName;

    stream >> name;
    stream >> x;
    stream >> y;
    stream >> credits;
    stream >> remainingSkill;
    stream >> pilotSkill;
    stream >> fighterSkill;
    stream >> traderSkill;
    stream >> engineerSkill;
    stream >> investorSkill;
    stream >> systemName;

    player.setName(name);
    player.setX(x);
    player.setY(y);
    player.setCredits(credits);
    player.setRemainingSkill(remainingSkill);
    player.setPilotSkill(pilotSkill);
    player.setFighterSkill(fighterSkill);
    player.setTraderSkill(traderSkill);
    player.setEngineerSkill(engineerSkill);
    player.setInvestorSkill(investorSkill);
    player.setCurrentSystem(Galaxy::getInstance().getSolarSystem(systemName));

    return stream;
}
