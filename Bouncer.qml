import QtQuick 2.15

Rectangle {
    property int moved: 0
    readonly property int step: 15

    width: 200
    height: 8
    radius: 2
    color: "gray"
    focus: true
    anchors.horizontalCenterOffset: moved

    Keys.onLeftPressed: {
        moved -= step
    }
    Keys.onRightPressed: {
        moved += step
    }
}
