#include "galaxy.h"
#include <QMap>
#include <QSharedData>
#include <QStringList>
#include <QTime>

Galaxy Galaxy::instance = Galaxy();

class GalaxyData : public QSharedData {
public:
    QMap<QString, SolarSystem> solarSystems;
};

Galaxy::Galaxy() : data(new GalaxyData)
{
    qsrand(QTime::currentTime().msec());

    QStringList systemNames;
    systemNames.append("Earth616");
    systemNames.append("Utopia");
    systemNames.append("Omega");
    systemNames.append("Tantalos");
    systemNames.append("Carzon");
    systemNames.append("Exo");
    systemNames.append("Destiny");
    systemNames.append("Frolix");
    systemNames.append("Acamar");
    systemNames.append("Adahn"); // The alternate personality for The Nameless One in "Planescape: Torment"
    systemNames.append("Aldea");
    systemNames.append("Andevian");
    systemNames.append("Antedi");
    systemNames.append("Balosnee");
    systemNames.append("Baratas");
    systemNames.append("Brax"); // One of the heroes in Master of Magic
    systemNames.append("Bretel"); // This is a Dutch device for keeping your pants up.
    systemNames.append("Calondia");
    systemNames.append("Campor");
    systemNames.append("Capelle"); // The city I lived in while programming this game
    systemNames.append("Carzon");
    systemNames.append("Castor"); // A Greek demi-god
    systemNames.append("Cestus");
    systemNames.append("Cheron");
    systemNames.append("Courteney"); // After Courteney Cox…
    systemNames.append("Daled");
    systemNames.append("Damast");
    systemNames.append("Davlos");
    systemNames.append("Deneb");
    systemNames.append("Deneva");
    systemNames.append("Devidia");
    systemNames.append("Draylon");
    systemNames.append("Drema");
    systemNames.append("Endor");
    systemNames.append("Esmee"); // One of the witches in Pratchett's Discworld
    systemNames.append("Exo");
    systemNames.append("Ferris"); // Iron
    systemNames.append("Festen"); // A great Scandinavian movie
    systemNames.append("Fourmi"); // An ant, in French
    systemNames.append("Frolix"); // A solar system in one of Philip K. Dick's novels
    systemNames.append("Gemulon");
    systemNames.append("Guinifer"); // One way of writing the name of king Arthur's wife
    systemNames.append("Hades"); // The underworld
    systemNames.append("Hamlet"); // From Shakespeare
    systemNames.append("Helena"); // Of Troy
    systemNames.append("Hulst"); // A Dutch plant
    systemNames.append("Iodine"); // An element
    systemNames.append("Iralius");
    systemNames.append("Janus"); // A seldom encountered Dutch boy's name
    systemNames.append("Japori");
    systemNames.append("Jarada");
    systemNames.append("Jason"); // A Greek hero
    systemNames.append("Kaylon");
    systemNames.append("Khefka");
    systemNames.append("Kira"); // My dog's name
    systemNames.append("Klaatu"); // From a classic SF movie
    systemNames.append("Klaestron");
    systemNames.append("Korma"); // An Indian sauce
    systemNames.append("Kravat"); // Interesting spelling of the French word for "tie"
    systemNames.append("Krios");
    systemNames.append("Laertes"); // A king in a Greek tragedy
    systemNames.append("Largo");
    systemNames.append("Lave"); // The starting system in Elite
    systemNames.append("Ligon");
    systemNames.append("Lowry"); // The name of the "hero" in Terry Gilliam's "Brazil"
    systemNames.append("Magrat"); // The second of the witches in Pratchett's Discworld
    systemNames.append("Malcoria");
    systemNames.append("Melina");
    systemNames.append("Mentar"); // The Psilon home system in Master of Orion
    systemNames.append("Merik");
    systemNames.append("Mintaka");
    systemNames.append("Montor"); // A city in Ultima III and Ultima VII part 2
    systemNames.append("Mordan");
    systemNames.append("Myrthe"); // The name of my daughter
    systemNames.append("Nelvana");
    systemNames.append("Nix"); // An interesting spelling of a word meaning "nothing" in Dutch
    systemNames.append("Nyle"); // An interesting spelling of the great river
    systemNames.append("Odet");
    systemNames.append("Og"); // The last of the witches in Pratchett's Discworld
    systemNames.append("Omega"); // The end of it all
    systemNames.append("Omphalos"); // Greek for navel
    systemNames.append("Orias");
    systemNames.append("Othello"); // From Shakespeare
    systemNames.append("Parade"); // This word means the same in Dutch and in English
    systemNames.append("Penthara");
    systemNames.append("Picard"); // The enigmatic captain from ST:TNG
    systemNames.append("Pollux"); // Brother of Castor
    systemNames.append("Quator");
    systemNames.append("Rakhar");
    systemNames.append("Ran"); // A film by Akira Kurosawa
    systemNames.append("Regulas");
    systemNames.append("Relva");
    systemNames.append("Rhymus");
    systemNames.append("Rochani");
    systemNames.append("Rubicum"); // The river Ceasar crossed to get into Rome
    systemNames.append("Rutia");
    systemNames.append("Sarpeidon");
    systemNames.append("Sefalla");
    systemNames.append("Seltrice");
    systemNames.append("Sigma");
    systemNames.append("Sol"); // That's our own solar system
    systemNames.append("Somari");
    systemNames.append("Stakoron");
    systemNames.append("Styris");
    systemNames.append("Talani");
    systemNames.append("Tamus");
    systemNames.append("Tantalos"); // A king from a Greek tragedy
    systemNames.append("Tanuga");
    systemNames.append("Tarchannen");
    systemNames.append("Terosa");
    systemNames.append("Thera"); // A seldom encountered Dutch girl's name
    systemNames.append("Titan"); // The largest moon of Jupiter
    systemNames.append("Torin"); // A hero from Master of Magic
    systemNames.append("Triacus");
    systemNames.append("Turkana");
    systemNames.append("Tyrus");
    systemNames.append("Umberlee"); // A god from AD&D, which has a prominent role in Baldur's Gate
    systemNames.append("Utopia"); // The ultimate goal
    systemNames.append("Vadera");
    systemNames.append("Vagra");
    systemNames.append("Vandor");
    systemNames.append("Ventax");
    systemNames.append("Xenon");
    systemNames.append("Xerxes"); // A Greek hero
    systemNames.append("Yew"); // A city which is in almost all of the Ultima games
    systemNames.append("Yojimbo"); // A film by Akira Kurosawa
    systemNames.append("Zalkon");
    systemNames.append("Zuul");

    for (int i = 0; i < systemNames.size(); i++) {
        QString name = systemNames.at(i);
        data->solarSystems.insert(name, SolarSystem(name));
    }
}

Galaxy::Galaxy(QList<SolarSystem> solarSystems)
    : data(new GalaxyData)
{
    for (int i = 0; i < solarSystems.size(); i++) {
        data->solarSystems.insert(solarSystems.at(i).getName(), solarSystems.at(i));
    }
}

Galaxy::Galaxy(const Galaxy &rhs) : data(rhs.data)
{
}

const QList<SolarSystem> Galaxy::getSolarSystems() const {
    return data->solarSystems.values();
}

const SolarSystem Galaxy::getSolarSystem(QString name) const {
    return data->solarSystems.value(name);
}

Galaxy Galaxy::getInstance() {
    return instance;
}

Galaxy &Galaxy::operator=(const Galaxy &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Galaxy::~Galaxy()
{
}

QDataStream& operator<<(QDataStream& stream, const Galaxy galaxy) {
    stream << galaxy.getSolarSystems();

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Galaxy& galaxy) {
    QList<SolarSystem> solarSystems;

    stream >> solarSystems;

    galaxy = Galaxy(solarSystems);

    return stream;
}
