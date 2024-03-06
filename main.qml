import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: screenWidth
    height: screenHeight
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text: "This will be atari breakout eventually"
    }
}
