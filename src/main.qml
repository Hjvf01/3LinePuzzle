import QtQuick 2.5
import QtQuick.Window 2.2


import Models 1.0


Window {
    visible: true
    width: 480
    height: 480
    title: qsTr("Hello World")
    color: "white"

    GridView {
        id: gridView
        model: TModel {}

        anchors.margins: 1
        anchors.fill: parent

        cellWidth: width / model._w()
        cellHeight: height / model._h()

        delegate: Item {
            id: gridDelegate
            width: gridView.cellWidth
            height: gridView.cellHeight
            Rectangle {
                anchors.margins: 1
                anchors.fill: parent
                color: "red"
                radius: width / 2
            }
        }

        highlight: Rectangle {
            color: "cyan"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                gridView.currentIndex = gridView.indexAt(mouse.x, mouse.y);
            }
        }
    }
}
