import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent

    Button {
        id: button1
        text: qsTr("New Game")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.right: parent.right
        anchors.rightMargin: 8
        onClicked: mainController.startNewGame()
    }

    Button {
        id: button2
        text: qsTr("Settings")
        anchors.top: button1.bottom
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        onClicked: mainController.showSettings()
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
