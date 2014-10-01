import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    width: 600
    height: 640
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    Button {
        id: marketplaceButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Marketplace"
    }

    Rectangle {
        id: mapRegion
        color: "#00000000"
        anchors.top: marketplaceButton.bottom
        anchors.topMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    function createSpriteObjects(name, x, y) {
        component = Qt.createComponent("Planet.qml");
        sprite = component.createObject(mapRegion, {"solarSystemName": name, "x": x, "y": y});

        if (sprite == null) {
            console.log("Error creating object");
        }
    }
}
