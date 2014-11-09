import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    objectName: "marketplaceScreen"
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    property int creditsAvailable
    property int creditChanges

    Label {
        id: creditsAvailableLabel
        text: qsTr("Credits Available: ")  + creditsAvailable
        color: "orange"
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    Label {
        id: creditChangesLabel
        text: qsTr("Credit Changes: ")  + creditChanges
        color: "orange"
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    Component {
        id: gridItem
        Rectangle {
            width: gridView1.cellWidth;
            height: gridView1.cellHeight
            border.color: "orange"
            border.width: 1
            radius: 5
            color: "transparent"
            Text {
                text: ware
                color: "orange"
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    gridView1.currentIndex = index;
                    displayItemInfo.ware = ware;
                    displayItemInfo.price = price;
                    displayItemInfo.planetQuantity = planetQuantity;
                    displayItemInfo.shipQuantity = shipQuantity;
                }
                onEntered: parent.border.color = "blue"
                onExited: parent.border.color = "orange"
                hoverEnabled: true
            }
        }
    }

    SplitView {
        orientation: Qt.Vertical
        anchors.top: creditsAvailableLabel.bottom
        anchors.topMargin: 6
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.bottom: button1.top
        anchors.bottomMargin: 6

        GridView {
            id: gridView1
            height: 150
            model: ListModel {}
            cellHeight: 75
            cellWidth: 75
            delegate: gridItem
            highlight: Rectangle {
                color: "lightsteelblue";
                radius: 5
            }
            focus: true
            clip: true
            currentIndex: -1
        }

        Item {
            id: displayItemInfo

            property string ware
            property int price
            property int planetQuantity
            property int shipQuantity

            Item {
                id: itemPriceGroup
                anchors.top: parent.top
                anchors.topMargin: 8
                anchors.horizontalCenter: parent.horizontalCenter
                implicitHeight: priceDisplayLabel.height
                implicitWidth: priceLabel.width + priceDisplayLabel.width + 6

                Label {
                    id: priceLabel
                    text: qsTr("Price: ")
                    color: "orange"
                }
                Label {
                    id: priceDisplayLabel
                    anchors.left: priceLabel.right
                    anchors.leftMargin: 6
                    text: displayItemInfo.price
                    color: "orange"
                }
            }

            Label {
                id: quantityPlanetLabel
                text: qsTr("Quantity on planet: ") + displayItemInfo.planetQuantity
                color: "orange"
                anchors.top: itemPriceGroup.bottom
                anchors.topMargin: 6
                anchors.left: parent.left
                anchors.leftMargin: 8
            }
            Button {
                id: buyItemButton
                text: qsTr("Buy item")
                enabled: displayItemInfo.planetQuantity > 0
                anchors.top: quantityPlanetLabel.bottom
                anchors.topMargin: 6
                anchors.left: parent.left
                anchors.leftMargin: 8
                onClicked: marketplace.buyItem(gridView1.currentIndex)
            }

            Label {
                id: quantityShipLabel
                text: qsTr("Quantity on ship: ") + displayItemInfo.shipQuantity
                color: "orange"
                anchors.top: itemPriceGroup.bottom
                anchors.topMargin: 6
                anchors.right: parent.right
                anchors.rightMargin: 8
            }
            Button {
                id: sellItemButton
                text: qsTr("Sell item")
                enabled: displayItemInfo.shipQuantity > 0
                anchors.top: quantityPlanetLabel.bottom
                anchors.topMargin: 6
                anchors.right: parent.right
                anchors.rightMargin: 8
                onClicked: marketplace.sellItem(gridView1.currentIndex)
            }
        }
    }

    Button {
        id: button1
        text: qsTr("Cancel Changes")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        onClicked: mainController.showNavigationPage()
    }

    Button {
        id: button2
        text: qsTr("Save Changes")
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        onClicked: {
            marketplace.saveChanges();
            mainController.showNavigationPage();
        }
    }

    function createProduct(ware, price, planetQuantity, shipQuantity) {
        gridView1.model.append({"ware": ware, "price": price,
                                   "planetQuantity": planetQuantity, "shipQuantity": shipQuantity});
    }

    function getProduct(index) {
        return (index < gridView1.model.count) ? gridView1.model.get(index) : 0;
    }

    function setProduct(index, product, updateInfoDisplay) {
        gridView1.model.set(index, product);
        if (updateInfoDisplay) {
            displayItemInfo.ware = product.ware;
            displayItemInfo.price = product.price;
            displayItemInfo.planetQuantity = product.planetQuantity;
            displayItemInfo.shipQuantity = product.shipQuantity;
        }
    }
}