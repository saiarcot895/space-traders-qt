import QtQuick 2.2
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0

Item {
    id: planetItem
    implicitHeight: image1.height + 1
    implicitWidth: image1.width + 1

    anchors.top: parent.verticalCenter
    anchors.left: parent.horizontalCenter

    property string planetName
    property color planetColor
    property double planetRadius
    property bool isCurrentPlanet

    property int rotationDuration: planetRadius * 20

    Rectangle {
        id: currentSystemRectangle
        color: "#00000000"
        border.color: "#FF00FF00"
        border.width: isCurrentPlanet ? 3 : 0
        radius: 5
        width: image1.width + 8
        height: image1.height + 8
        x: planetRadius

        Image {
            id: image1
            source: "qrc:///Planet.png"
            sourceSize: Qt.size(32, 32)
            anchors.horizontalCenter: currentSystemRectangle.horizontalCenter
            anchors.verticalCenter: currentSystemRectangle.verticalCenter

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    mouseEffect.brightness = 0.4;
                    systemLabelRectangle.visible = true;
                }
                onExited: {
                    mouseEffect.brightness = 0;
                    systemLabelRectangle.visible = false;
                }
                onClicked: setPlanet(planetName)
            }
        }

        ColorOverlay {
            id: colorEffect
            anchors.fill: image1
            source: image1
            color: planetColor
        }

        BrightnessContrast {
            id: mouseEffect
            anchors.fill: image1
            source: colorEffect
            brightness: 0
        }
    }

    Rectangle {
        id: systemLabelRectangle
        anchors.horizontalCenter: currentSystemRectangle.horizontalCenter
        anchors.top: currentSystemRectangle.bottom
        anchors.topMargin: 4
        color: "black"
        visible: false
        width: systemLabel.width + 8
        height: systemLabel.height + 8
        radius: 6
        z: 5

        Label {
            id: systemLabel
            text: planetName
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
        }
    }

    ParallelAnimation {
        id: neQuadMovement
        running: true
        onStopped: nwQuadMovement.start()

        PropertyAnimation {
            id: xMovement1
            target: currentSystemRectangle
            easing.type: Easing.InSine
            duration: rotationDuration
            property: "x"
            from: planetRadius
            to: 0
        }

        PropertyAnimation {
            id: yMovement1
            target: currentSystemRectangle
            easing.type: Easing.OutSine
            duration: rotationDuration
            property: "y"
            from: 0
            to: planetRadius
        }
    }

    ParallelAnimation {
        id: nwQuadMovement
        onStopped: swQuadMovement.start()

        PropertyAnimation {
            id: xMovement2
            target: currentSystemRectangle
            easing.type: Easing.OutSine
            duration: rotationDuration
            property: "x"
            from: 0
            to: -planetRadius
        }
        PropertyAnimation {
            id: yMovement2
            target: currentSystemRectangle
            easing.type: Easing.InSine
            duration: rotationDuration
            property: "y"
            from: planetRadius
            to: 0
        }
    }

    ParallelAnimation {
        id: swQuadMovement
        onStopped: seQuadMovement.start()

        PropertyAnimation {
            id: xMovement3
            target: currentSystemRectangle
            easing.type: Easing.InSine
            duration: rotationDuration
            property: "x"
            from: -planetRadius
            to: 0
        }

        PropertyAnimation {
            id: yMovement3
            target: currentSystemRectangle
            easing.type: Easing.OutSine
            duration: rotationDuration
            property: "y"
            from: 0
            to: -planetRadius
        }
    }

    ParallelAnimation {
        id: seQuadMovement
        onStopped: neQuadMovement.start()

        PropertyAnimation {
            id: xMovement4
            target: currentSystemRectangle
            easing.type: Easing.OutSine
            duration: rotationDuration
            property: "x"
            from: 0
            to: planetRadius
        }

        PropertyAnimation {
            id: yMovement4
            target: currentSystemRectangle
            easing.type: Easing.InSine
            duration: rotationDuration
            property: "y"
            from: -planetRadius
            to: 0
        }
    }
}
