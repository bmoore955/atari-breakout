import QtQuick 2.15

Rectangle {
    id: bouncerBase

    property Item ballTarget // Pass in the ball Item for checking bounce
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

    Connections {
        target: ballTarget
        ignoreUnknownSignals: true
        function onCheck() {
            // Check if we bounced off the top
            if ((ballTarget.x + ballTarget.width / 2 >= bouncerBase.x) &&
                (ballTarget.x - ballTarget.width / 2 <= bouncerBase.x + bouncerBase.width) &&
                (ballTarget.y + ballTarget.height >= bouncerBase.y) &&
                (ballTarget.y + ballTarget.height <= bouncerBase.y + bouncerBase.height)) {
                ballTarget.goingDown = false
            }
        }
    }
}
