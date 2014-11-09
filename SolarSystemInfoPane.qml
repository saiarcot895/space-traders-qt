import QtQuick 2.2
import QtQuick.Controls 1.1

Rectangle {
    id: solarSystemInfoPane
    anchors.fill: parent.fill
    implicitWidth: solarSystemNameLabel.width + solarSystemName.width + 18
    implicitHeight: solarSystemNameLabel.height + solarSystemPlanetsLabel.height + 16
    color: "darkblue"

    property string solarSystemName: ""
    property int solarSystemPlanets: 0
    property bool travelEnabled: true

    Label {
        id: solarSystemNameLabel
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        color: "white"
        text: "Solar System: "
    }

    Label {
        id: solarSystemNameDisplay
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: solarSystemNameLabel.right
        anchors.leftMargin: 6
        color: "white"
        text: solarSystemName
    }

    Label {
        id: solarSystemPlanetsLabel
        anchors.top: solarSystemNameLabel.bottom
        anchors.topMargin: 6
        anchors.left: parent.left
        anchors.leftMargin: 8
        color: "white"
        text: "Planets: "
    }

    Label {
        id: solarSystemPlanetsDisplay
        anchors.top: solarSystemName.bottom
        anchors.topMargin: 6
        anchors.left: solarSystemPlanetsLabel.right
        anchors.leftMargin: 6
        color: "white"
        text: solarSystemPlanets
    }

    Button {
        id: travelToSolarSystemButton
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.verticalCenter: parent.verticalCenter
        enabled: travelEnabled
        text: "Travel to " + solarSystemName
    }
}
