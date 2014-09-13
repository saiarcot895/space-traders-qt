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

private:
    QObject *rootObject;

};

#endif // NEWGAME_H
