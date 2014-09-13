#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlApplicationEngine>

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();

    Q_INVOKABLE void startNewGame();
    Q_INVOKABLE void showSettings();

private:
    QQmlApplicationEngine* engine;
    QObject* rootObject;

};

#endif // MAINWINDOW_H
