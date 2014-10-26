import QtQuick 2.2
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0

Item {
    property string solarSystemName
    implicitHeight: image1.height + 1
    implicitWidth: image1.width + 1

    Image {
        id: image1
        source: "qrc:///Planet.png"
        sourceSize: Qt.size(24, 24)

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
        color: "#80800000"
    }

    BrightnessContrast {
        id: mouseEffect
        anchors.fill: image1
        source: colorEffect
        brightness: 0
    }

    Rectangle {
        id: systemLabelRectangle
        anchors.horizontalCenter: image1.horizontalCenter
        anchors.top: image1.bottom
        anchors.topMargin: 4
        color: "black"
        visible: false
        width: systemLabel.width + 8
        height: systemLabel.height + 8
        radius: 6
        z: 5

        Label {
            id: systemLabel
            text: solarSystemName
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
        }
    }
}
