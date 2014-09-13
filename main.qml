import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

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
}
