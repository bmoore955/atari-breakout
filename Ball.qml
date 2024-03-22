import QtQuick 2.15

Rectangle {
    id: ballBase

    // These combined provide the direction of the ball
    property bool goingRight: true
    property bool goingDown: false

    width: 14
    height: width
    radius: width / 2
    color: "gray"

    signal check()

    // Serves to continuously update the velocity of the ball
    Timer {
        interval: 15
        running: true
        repeat: true
        onTriggered: {
            // Increment/Decrement ball position then check for changes in direction
            ballBase.x += goingRight ? 2 : -2
            ballBase.y += goingDown ? 2 : -2

            // Bounce off walls
            checkWalls()

            // Emit signal to check for bouncing off paddle
            ballBase.check()
        }

        // Checks whether the ball is going offscreen
        function checkWalls() {
            if (ballBase.x <= 0)
                goingRight = true
            if (ballBase.y <= 0)
                goingDown = true
            if (ballBase.x + ballBase.width >= screenWidth)
                goingRight = false
        }
    }
}
