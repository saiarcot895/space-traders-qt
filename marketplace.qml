import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Image {
    id: image1
    objectName: "marketplaceScreen"
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    Button {
        id: button1
        text: qsTr("Return to Map")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    Component {
        id: gridItem
        Rectangle {
            width: gridView1.cellWidth;
            height: gridView1.cellHeight
            border.width: 1
            radius: 5
            color: "transparent"
            Text {
                text: ware
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: gridView1.currentIndex = index
                onEntered: parent.border.color = "blue"
                onExited: parent.border.color = "black"
                hoverEnabled: true
            }
        }
    }

    SplitView {
        orientation: Qt.Vertical
        anchors.top: button1.bottom
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
        }

        Item {
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
                    text: qsTr("200")
                    color: "orange"
                }
            }
        }
    }

    function createProduct(ware, price, planetQuantity, shipQuantity) {
        gridView1.model.append({"ware": ware, "price": price,
                                   "planetQuantity": planetQuantity, "shipQuantity": shipQuantity});
    }
}
