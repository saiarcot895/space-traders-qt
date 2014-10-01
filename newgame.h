#ifndef NEWGAME_H
#define NEWGAME_H

#include <QObject>

class NewGame : public QObject
{
    Q_OBJECT
public:
    NewGame(QObject *rootObject = 0, QObject *parent = 0);

    void setRootObject(QObject *rootObject);
    void showNewGamePage();

    Q_INVOKABLE void incrementSkill(QObject* skillRectangle);
    Q_INVOKABLE void decrementSkill(QObject* skillRectangle);

    int getAvailableSkillPoints() const;
    int getPilotSkillPoints() const;
    int getFighterSkillPoints() const;
    int getEngineerSkillPoints() const;
    int getTraderSkillPoints() const;

private:
    QObject *rootObject;

    int availableSkillPoints;
    int pilotSkillPoints;
    int fighterSkillPoints;
    int engineerSkillPoints;
    int inventorSkillPoints;
    int traderSkillPoints;
};

#endif // NEWGAME_H
