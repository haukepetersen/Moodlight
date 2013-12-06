import QtQuick 2.0

Rectangle {
    width: parent.width
    height: 40

    color: "#353f3f"
    states: [
        State {
            name: "connected"
        }
    ]
    Rectangle {
        width: 0.7 * parent.width
        height: parent.height
        radius: 10
        color: "red"
    }
}
