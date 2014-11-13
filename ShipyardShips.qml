import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    id: image1
    objectName: "shipyardShips"
    anchors.fill: parent

    property int creditsAvailable
    property int creditChanges

    Label {
        id: creditsAvailableLabel
        text: qsTr("Credits Available: ")  + creditsAvailable
        color: "blue"
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    Label {
        id: creditChangesLabel
        text: qsTr("Credit Changes: ")  + creditChanges
        color: "blue"
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
            border.color: "blue"
            border.width: 1
            radius: 5
            color: "transparent"
            Label {
                text: shipName
                color: "blue"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.Wrap
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    gridView1.currentIndex = index;
                    displayItemInfo.shipName = shipName;
                    displayItemInfo.cargoCapacity = cargoCapacity;
                    displayItemInfo.maxHealth = maxHealth;
                    displayItemInfo.maxFuel = maxFuel;
                }
                onEntered: parent.border.color = "orange"
                onExited: parent.border.color = "blue"
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
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8

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

            property string currentShipName
            property int currentCargoCapacity
            property int currentMaxHealth
            property int currentMaxFuel

            property string shipName
            property int cargoCapacity
            property int maxHealth
            property int maxFuel

            Item {
                id: shipNameGroup
                anchors.top: parent.top
                anchors.topMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                implicitHeight: Math.max(currentShipName.height, shipNameLabel.height, newShipName.height)

                Label {
                    id: currentShipName
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    text: displayItemInfo.currentShipName
                    color: "blue"
                }
                Label {
                    id: shipNameLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Ship Name")
                    color: "blue"
                }
                Label {
                    id: newShipName
                    anchors.right: parent.right
                    anchors.rightMargin: 6
                    text: displayItemInfo.shipName
                    color: "blue"
                }
            }

            Item {
                id: cargoCapacityGroup
                anchors.top: shipNameGroup.bottom
                anchors.topMargin: 6
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                implicitHeight: Math.max(currentCargoCapacity.height, cargoCapacityLabel.height, newCargoCapacity.height)

                Label {
                    id: currentCargoCapacity
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    text: displayItemInfo.currentCargoCapacity
                    color: "blue"
                }
                Label {
                    id: cargoCapacityLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Cargo Capacity")
                    color: "blue"
                }
                Label {
                    id: newCargoCapacity
                    anchors.right: parent.right
                    anchors.rightMargin: 6
                    text: displayItemInfo.cargoCapacity
                    color: "blue"
                }
            }

            Item {
                id: maxHealthGroup
                anchors.top: cargoCapacityGroup.bottom
                anchors.topMargin: 6
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                implicitHeight: Math.max(currentMaxHealth.height, maxHealthLabel.height, newMaxHealth.height)

                Label {
                    id: currentMaxHealth
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    text: displayItemInfo.currentMaxHealth
                    color: "blue"
                }
                Label {
                    id: maxHealthLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Max Health")
                    color: "blue"
                }
                Label {
                    id: newMaxHealth
                    anchors.right: parent.right
                    anchors.rightMargin: 6
                    text: displayItemInfo.maxHealth
                    color: "blue"
                }
            }

            Item {
                id: maxFuelGroup
                anchors.top: maxHealthGroup.bottom
                anchors.topMargin: 6
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.right: parent.right
                anchors.rightMargin: 8
                implicitHeight: Math.max(currentMaxFuel.height, maxFuelLabel.height, newMaxFuel.height)

                Label {
                    id: currentMaxFuel
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    text: displayItemInfo.currentMaxHealth
                    color: "blue"
                }
                Label {
                    id: maxFuelLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Max Fuel")
                    color: "blue"
                }
                Label {
                    id: newMaxFuel
                    anchors.right: parent.right
                    anchors.rightMargin: 6
                    text: displayItemInfo.maxFuel
                    color: "blue"
                }
            }
        }
    }

    DialogBox {
        id: dialogBox
        z: 1
    }

    function createShip(shipName, cargoCapacity, maxHealth, maxFuel) {
        gridView1.model.append({"shipName": shipName, "cargoCapacity": cargoCapacity,
                                   "maxHealth": maxHealth, "maxFuel": maxFuel});
    }

    function getShip(index) {
        return (index < gridView1.model.count) ? gridView1.model.get(index) : 0;
    }

    function setShip(index, product, updateInfoDisplay) {
        gridView1.model.set(index, product);
        if (updateInfoDisplay) {
            displayItemInfo.shipName = product.shipName;
            displayItemInfo.cargoCapacity = product.cargoCapacity;
            displayItemInfo.maxHealth = product.maxHealth;
            displayItemInfo.maxFuel = product.maxFuel;
        }
    }

    function setCurrentShip(shipName, cargoCapacity, maxHealth, maxFuel) {
        displayItemInfo.currentShipName = shipName;
        displayItemInfo.currentCargoCapacity = cargoCapacity;
        displayItemInfo.currentMaxHealth = maxHealth;
        displayItemInfo.currentMaxFuel = maxFuel;
    }

    function showMessage(message) {
        dialogBox.message = message;
        dialogBox.showMessage();
    }
}
