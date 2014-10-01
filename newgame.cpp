#include "newgame.h"

#include <QVariant>

NewGame::NewGame(QObject *rootObject, QObject *parent) :
    QObject(parent),
    rootObject(rootObject),
    availableSkillPoints(8)
{

}

void NewGame::setRootObject(QObject *rootObject) {
    this->rootObject = rootObject;
}

void NewGame::showNewGamePage() {
    Q_ASSERT(rootObject);
    rootObject->findChild<QObject*>("pageLoader")->setProperty("source", QStringLiteral("qrc:///newgame.qml"));
    rootObject->findChild<QObject*>("availableSkillPoints")->setProperty("text", availableSkillPoints);
}

void NewGame::incrementSkill(QObject *skillRectangle) {
    int skillLevel = skillRectangle->property("skillLevel").toInt();
    if (availableSkillPoints == 0) {
        return;
    }
    if (skillLevel == 1) {
        skillRectangle->setProperty("isDecrementable", true);
    }
    skillRectangle->setProperty("skillLevel", skillLevel + 1);
    --availableSkillPoints;
    rootObject->findChild<QObject*>("availableSkillPoints")->setProperty("text", availableSkillPoints);
}

void NewGame::decrementSkill(QObject *skillRectangle) {
    int skillLevel = skillRectangle->property("skillLevel").toInt();
    skillRectangle->setProperty("skillLevel", skillLevel - 1);
    if (skillLevel - 1 == 1) {
        skillRectangle->setProperty("isDecrementable", false);
    }
    ++availableSkillPoints;
    rootObject->findChild<QObject*>("availableSkillPoints")->setProperty("text", availableSkillPoints);
}
