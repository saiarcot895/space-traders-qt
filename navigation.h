#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>

class Navigation : public QObject
{
    Q_OBJECT
public:
    explicit Navigation(QObject *rootObject = 0, QObject *parent = 0);

    void setRootObject(QObject* rootObject);
    void showNavigationPage();

private:
    QObject *rootObject;

};

#endif // NAVIGATION_H
