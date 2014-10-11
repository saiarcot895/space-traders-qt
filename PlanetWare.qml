import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    id: item1
    width: 500
    height: Math.max(button1.height) + 16

    property string ware
    property int price
    property int planetQuantity
    property int shipQuantity

    Label {
        id: label1
        text: ware
        anchors.left: parent.left
        anchors.leftMargin: 6
        anchors.verticalCenter: button1.verticalCenter
    }

    Label {
        id: label2
        text: price
        anchors.left: label1.left
        anchors.leftMargin: 70
        anchors.verticalCenter: button1.verticalCenter
    }

    Label {
        id: label3
        text: planetQuantity
        anchors.left: label2.left
        anchors.leftMargin: 50
        anchors.verticalCenter: button1.verticalCenter
    }

    Button {
        id: button1
        text: qsTr("Buy Item")
        enabled: planetQuantity > 0
        anchors.left: label3.left
        anchors.leftMargin: 44
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    Label {
        id: label4
        text: shipQuantity
        anchors.left: button1.right
        anchors.leftMargin: 56
        anchors.verticalCenter: button1.verticalCenter
    }

    Button {
        id: button2
        text: qsTr("Sell Item")
        enabled: shipQuantity > 0
        anchors.left: label4.left
        anchors.leftMargin: 72
        anchors.top: parent.top
        anchors.topMargin: 8
    }
}
