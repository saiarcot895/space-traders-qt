import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1

Image {
    id: image1
    objectName: "marketplaceScreen"
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    Label {
        id: wareLabel
        text: qsTr("Ware")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.verticalCenter: buyItemButton.verticalCenter
    }

    Label {
        id: priceLabel
        text: qsTr("Price")
        anchors.left: wareLabel.left
        anchors.leftMargin: 70
        anchors.verticalCenter: buyItemButton.verticalCenter
    }

    Label {
        id: planetQuantityLabel
        text: qsTr("Quantity")
        anchors.left: priceLabel.right
        anchors.leftMargin: 8
        anchors.verticalCenter: buyItemButton.verticalCenter
    }

    Button {
        id: buyItemButton
        text: qsTr("Buy Item")
        anchors.left: planetQuantityLabel.right
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
        visible: false
    }

    Label {
        id: shipQuantityLabel
        text: qsTr("Quantity on Ship")
        anchors.left: buyItemButton.right
        anchors.leftMargin: 16
        anchors.verticalCenter: buyItemButton.verticalCenter
    }

    Button {
        id: sellItemButton
        text: qsTr("Sell Item")
        anchors.left: shipQuantityLabel.right
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
        visible: false
    }

    Column {
        id: column1
        height: 400
        anchors.top: buyItemButton.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    function createProduct(ware, price, planetQuantity, shipQuantity) {
        var component = Qt.createComponent("PlanetWare.qml");
        var sprite = component.createObject(column1, {"ware": ware, "price": price,
                                                "planetQuantity": planetQuantity, "shipQuantity": shipQuantity});

        if (sprite === null) {
            console.log("Error creating object");
        }
    }
}
