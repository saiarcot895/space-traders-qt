import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    width: 600
    height: 640
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent

    Label {
        id: label1
        y: 8
        text: qsTr("Name")
        anchors.verticalCenter: textField1.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    TextField {
        id: textField1
        anchors.left: label1.right
        anchors.leftMargin: 6
        anchors.top: parent.top
        anchors.topMargin: 8
        placeholderText: qsTr("Name")
    }

    Rectangle {
        id: rectangle1
        height: 200
        color: "#00000000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8

        Loader {
            id: pilotSkill
            property string skillName: "Pilot"
            sourceComponent: skill
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
        }

        Loader {
            id: fighterSkill
            property string skillName: "Fighter"
            sourceComponent: skill
            anchors.top: pilotSkill.bottom
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
        }

        Loader {
            id: engineerSkill
            property string skillName: "Engineer"
            sourceComponent: skill
            anchors.top: fighterSkill.bottom
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
        }

        Loader {
            id: traderSkill
            property string skillName: "Trader"
            sourceComponent: skill
            anchors.top: engineerSkill.bottom
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
        }

        Loader {
            id: investorSkill
            property string skillName: "Investor"
            sourceComponent: skill
            anchors.top: traderSkill.bottom
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
        }
    }

    Component {
        id: skill

        Rectangle {
            id: skillRectangle
            property bool isIncrementable: true
            property bool isDecrementable: false
            property string skillLevel: "1"
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            height: 25
            color: "#00000000"

            Label {
                id: label2
                text: skillName
                color: "orange"
                anchors.verticalCenter: textField2.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 8
            }

            Button {
                id: button1
                width: 48
                text: "-"
                enabled: isDecrementable
                anchors.verticalCenter: textField2.verticalCenter
                anchors.left: label2.right
                anchors.leftMargin: 6
                onClicked: newGame.decrementSkill(skillRectangle)
            }

            TextField {
                id: textField2
                width: 45
                readOnly: true
                anchors.top: parent.top
                anchors.topMargin: 4
                anchors.left: button1.right
                anchors.leftMargin: 6
                text: skillLevel
            }

            Button {
                id: button2
                width: 48
                text: "+"
                enabled: isIncrementable
                anchors.verticalCenter: textField2.verticalCenter
                anchors.left: textField2.right
                anchors.leftMargin: 6
                onClicked: newGame.incrementSkill(skillRectangle)
            }
        }
    }

    Button {
        id: button3
        y: 609
        text: qsTr("Cancel")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    Button {
        id: button4
        x: 512
        y: 609
        text: qsTr("Create")
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
    }
}
