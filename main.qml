import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Space Traders")

    Loader {
        id: pageLoader
        objectName: "pageLoader"
        anchors.fill: parent
    }
}
