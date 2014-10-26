import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    objectName: "navigationScreen"
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
        onClicked: mainController.showMarketplace()
    }

    Rectangle {
        border.color: "blue"
        color: "transparent"
        clip: true

        Flickable {
            id: mapRegion
            objectName: "mapRegion"
            contentWidth: 2000
            contentHeight: 2000
            boundsBehavior: Flickable.DragOverBounds
            anchors.fill: parent
        }

        anchors.top: marketplaceButton.bottom
        anchors.topMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8

        Rectangle {
            id: verticalScrollbar
            anchors.right: mapRegion.right
            y: mapRegion.visibleArea.yPosition * mapRegion.height
            width: 10
            height: mapRegion.visibleArea.heightRatio * mapRegion.height
            color: "gray"
        }

        Rectangle {
            id: horizontalScrollbar
            anchors.bottom: mapRegion.bottom
            x: mapRegion.visibleArea.xPosition * mapRegion.width
            height: 10
            width: mapRegion.visibleArea.widthRatio * mapRegion.width
            color: "gray"
        }
    }

    function createPlanetButtons(name, x, y) {
        var component = Qt.createComponent("SolarSystem.qml");
        var sprite = component.createObject(mapRegion.contentItem, {"solarSystemName": name, "x": x, "y": y});

        if (sprite === null) {
            console.log("Error creating object");
        }
    }
}
