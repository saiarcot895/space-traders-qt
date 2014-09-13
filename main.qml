import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Space Traders")

    Image {
        id: image1
        z: -1
        anchors.fill: parent
        source: "qrc:///2015-Star-Citizen.jpg"
        fillMode: Image.PreserveAspectCrop
    }

    Button {
        id: button1
        text: qsTr("New Game")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    Button {
        id: button2
        text: qsTr("Settings")
        anchors.top: button1.bottom
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }

    Label {
        id: label1
        text: qsTr("Space Traders")
        font.pointSize: 24
        color: "gray"
        anchors.right: parent.right
        anchors.rightMargin: 8
    }
}
