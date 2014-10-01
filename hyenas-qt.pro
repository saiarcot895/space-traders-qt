TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    newgame.cpp \
    maincontroller.cpp \
    mainwindow.cpp \
    settings.cpp \
    galaxy.cpp \
    planet.cpp \
    solarsystem.cpp \
    navigation.cpp \
    player.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    newgame.h \
    maincontroller.h \
    mainwindow.h \
    settings.h \
    galaxy.h \
    planet.h \
    solarsystem.h \
    navigation.h \
    player.h
