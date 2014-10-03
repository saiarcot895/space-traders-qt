import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    id: item1
    width: 300
    height: 40

    property string ware

    Label {
        id: label1
        text: qsTr("Ware")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    Label {
        id: label2
        text: qsTr("Price")
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 8
    }
}
