import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    property string solarSystemName
    implicitHeight: solarSystemButton.height
    implicitWidth: solarSystemButton.width

    Button {
        id: solarSystemButton
        text: solarSystemName
    }
}
