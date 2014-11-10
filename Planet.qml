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
    property int planetRadius
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
                    mouseEffect.brightness = 0
                    systemLabelRectangle.visible = false;
                }
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

    PropertyAnimation {
        id: xMovement1
        target: currentSystemRectangle
        running: true
        easing.type: Easing.InSine
        duration: rotationDuration
        property: "x"
        from: planetRadius
        to: 0
        onStopped: xMovement2.start()
    }

    PropertyAnimation {
        id: xMovement2
        target: currentSystemRectangle
        easing.type: Easing.OutSine
        duration: rotationDuration
        property: "x"
        from: 0
        to: -planetRadius
        onStopped: xMovement3.start()
    }

    PropertyAnimation {
        id: xMovement3
        target: currentSystemRectangle
        easing.type: Easing.InSine
        duration: rotationDuration
        property: "x"
        from: -planetRadius
        to: 0
        onStopped: xMovement4.start()
    }

    PropertyAnimation {
        id: xMovement4
        target: currentSystemRectangle
        easing.type: Easing.OutSine
        duration: rotationDuration
        property: "x"
        from: 0
        to: planetRadius
        onStopped: xMovement1.start()
    }

    PropertyAnimation {
        id: yMovement1
        target: currentSystemRectangle
        running: true
        easing.type: Easing.OutSine
        duration: rotationDuration
        property: "y"
        from: 0
        to: planetRadius
        onStopped: yMovement2.start()
    }

    PropertyAnimation {
        id: yMovement2
        target: currentSystemRectangle
        easing.type: Easing.InSine
        duration: rotationDuration
        property: "y"
        from: planetRadius
        to: 0
        onStopped: yMovement3.start()
    }

    PropertyAnimation {
        id: yMovement3
        target: currentSystemRectangle
        easing.type: Easing.OutSine
        duration: rotationDuration
        property: "y"
        from: 0
        to: -planetRadius
        onStopped: yMovement4.start()
    }

    PropertyAnimation {
        id: yMovement4
        target: currentSystemRectangle
        easing.type: Easing.InSine
        duration: rotationDuration
        property: "y"
        from: -planetRadius
        to: 0
        onStopped: yMovement1.start()
    }
}
