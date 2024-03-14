import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: screenWidth
    height: screenHeight
    visible: true
    title: qsTr("Hello World")
    visibility: Window.Minimized

    Column {
        width: parent.width
        spacing: 2
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

        Row {
            width: parent.width
            height: 50
            spacing: 2
            Repeater {

                model: blocks.row2.length
                delegate: Rectangle {
                    color: "orange"
                    width: blocks.row2[index]
                    height: 50
                }
            }
        }

        Row {
            width: parent.width
            height: 50
            spacing: 2
            Repeater {

                model: blocks.row3.length
                delegate: Rectangle {
                    color: "yellow"
                    width: blocks.row3[index]
                    height: 50
                }
            }
        }

        Row {
            width: parent.width
            height: 50
            spacing: 2
            Repeater {

                model: blocks.row4.length
                delegate: Rectangle {
                    color: "green"
                    width: blocks.row4[index]
                    height: 50
                }
            }
        }
    }
}
