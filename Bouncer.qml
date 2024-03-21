import QtQuick 2.15

Rectangle {
    id: bouncerBase

    property int moved: 0
    readonly property int step: 15

    width: 200
    height: 8
    radius: 2
    color: "gray"
    focus: true
    anchors.horizontalCenterOffset: moved

    // Checks to make sure the bouncer can't go outside the screen
    Keys.onLeftPressed: moved -= (bouncerBase.x < step) ? bouncerBase.x : step
    Keys.onRightPressed: {
        var dist = bouncerBase.x + 200
        moved += (screenWidth - dist < step) ? screenWidth - dist : step
    }
}
