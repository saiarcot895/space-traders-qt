import QtQuick 2.2
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0

Item {
    property string solarSystemName
    implicitHeight: image1.height
    implicitWidth: image1.width

    Image {
        id: image1
        source: "qrc:///Planet.png"
        sourceSize: Qt.size(32, 32)

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: mouseEffect.brightness = 0.4
            onExited: mouseEffect.brightness = 0
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
}
