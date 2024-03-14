import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    title: qsTr("Hello World")
    visibility: Window.Minimized
    width: screenWidth
    height: screenHeight
    color: "black"

    Column {
        id: blocksCol

        readonly property int space: 2

        spacing: space
        anchors {
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: -50
        }

        Row {
            spacing: blocksCol.space

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
            spacing: blocksCol.space

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
            spacing: blocksCol.space

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
            spacing: blocksCol.space

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
