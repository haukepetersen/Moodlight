import QtQuick 2.0

Rectangle {
	id: root
	width: 600
	height: 400
	color: "#2a2a2a"

	property string errorMssg: comm.error


    MouseArea {
		id: globalMouse
		hoverEnabled: true
		anchors.fill: parent
		onClicked: {
			console.log("Heinz: " + comm.isOpen())
			comm.error = "Foobar ja."
		}
		onEntered: {
			console.log("Out")
			console.log("Connected: " + comm.isOpen())
		}
		onExited: {
			console.log("In")
		}
    }

	Column {
		anchors.fill: parent
		anchors.margins: 10
		spacing: 10

		Rectangle {
			width: parent.width
			height: 30
			radius: 10
			color: "#353535"

			Text {
				id: txtConnect
				anchors.centerIn: parent
				text: qsTr("Not Connected")
				color: "#e1e1e1"
			}
			MouseArea {
				anchors.fill: parent
				onClicked: comm.open();
			}
		}

		Rectangle {
			id: errorBar
			width: parent.width
			height: 25
			color: "#353535"
			Text {
				anchors.centerIn: parent
				text: comm.error
				color: "#e1e1e1"
				onTextChanged: {
					parent.color = (parent.color == "green") ? "red" : "green"
				}
			}
		}

		Rectangle {
			width: parent.width
			height: parent.height - 40
			radius: 10
			color: "#353535"
		}

	}
}
