import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: screenWidth
    height: screenHeight
    visible: true
    title: qsTr("Hello World")
    visibility: Window.Minimized

    Row {
        width: parent.width
        height: 50
        spacing: 2
        Repeater {

            model: blocks.row1.length
            delegate: Rectangle {
                color: "red"
                width: blocks.row1[index]
                height: 50
            }
        }
    }
}
