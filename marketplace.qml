import QtQuick 2.2
import QtQuick.Controls 1.1

Image {
    id: image1
    source: "qrc:///2015-Star-Citizen.jpg"
    fillMode: Image.PreserveAspectCrop
    anchors.fill: parent
    z: -1

    Label {
        id: label1
        text: qsTr("Ware")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    Label {
        id: label2
        text: qsTr("Price")
        anchors.left: label1.right
        anchors.leftMargin: 16
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    Label {
        id: label3
        text: qsTr("Quantity Available")
        anchors.left: label2.right
        anchors.leftMargin: 16
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    Label {
        id: label4
        text: qsTr("Quantity Sellable")
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: label3.right
        anchors.leftMargin: 48
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    ListModel {
       id: libraryModel
       ListElement{ title: "A Masterpiece" ; author: "Gabriel" }
       ListElement{ title: "Brilliance"    ; author: "Jens" }
       ListElement{ title: "Outstanding"   ; author: "Frederik" }
    }

    TableView {
       TableViewColumn{ role: "title"  ; title: "Title" ; width: 100 }
       TableViewColumn{ role: "author" ; title: "Author" ; width: 200 }
       model: libraryModel
       backgroundVisible: false
    }
}
