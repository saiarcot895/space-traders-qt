import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    objectName: "planetNavigationScreen"
    width: 600
    height: 640
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    property string planetName
    property bool smallIcon: parent !== null && parent.width <= navigationPageButton.width + marketplaceButton.width + shipyardButton.width + 24

    Button {
        id: navigationPageButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        text: "Back to Navigation Page"
        visible: !smallIcon
        onClicked: mainController.showNavigationPage()
    }

    Button {
        id: smallNavigationPageButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        text: "←"
        visible: smallIcon
        onClicked: mainController.showNavigationPage()
    }

    Button {
        id: marketplaceButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        text: "Marketplace"
        onClicked: mainController.showMarketplace()
    }

    Button {
        id: shipyardButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: marketplaceButton.left
        anchors.rightMargin: 6
        text: "Shipyard"
        visible: !smallIcon
        onClicked: mainController.showShipyard()
    }

    Button {
        id: smallShipyardButton
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: marketplaceButton.left
        anchors.rightMargin: 6
        text: "🚀"
        visible: smallIcon
        onClicked: mainController.showShipyard()
    }

    Rectangle {
        id: solarSystemView
        border.color: "blue"
        color: "transparent"
        clip: true
        anchors.top: marketplaceButton.bottom
        anchors.topMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    Rectangle {
        id: planetInfoPane
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width * 0.6
        height: parent.height * 0.6
        color: "#7F0000BF"
        border.color: "#7F00004F"
        border.width: 5
        radius: 10
        visible: false

        Label {
            id: planetNameLabel
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            color: "white"
            text: "Planet: "
        }

        Label {
            id: planetNameDisplay
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.left: planetNameLabel.right
            anchors.leftMargin: 6
            color: "white"
            text: planetName
        }

        Button {
            id: cancelButton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            text: "Cancel"
            onClicked: planetInfoPane.visible = false
        }

        Button {
            id: travelToSolarSystemButton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 8
            text: "Travel to " + planetName
            onClicked: {
                planetNavigation.travelToPlanet(planetName);
                planetInfoPane.visible = false;
            }
        }
    }

    function createPlanetButtons(name, color, radius, isCurrentPlanet) {
        var component = Qt.createComponent("Planet.qml");
        var sprite = component.createObject(solarSystemView, {"planetName": name, "planetColor": color,
                                                "planetRadius": radius, "isCurrentPlanet": isCurrentPlanet});

        if (sprite === null) {
            console.log("Error creating object");
        }
    }

    function setPlanet(name) {
        planetName = name;
        planetInfoPane.visible = true;
    }

    function setNewCurrentPlanet(name) {
        for (var i in solarSystemView.children) {
            var item = solarSystemView.children[i];
            item.isCurrentPlanet = item.planetName === name;
        }
    }
}
