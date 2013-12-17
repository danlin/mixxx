import QtQuick 2.2

Item {
	property var borderSize: 0;
	property var borderColor: black;
	property var color: withe;
	Rectangle {
    	width: parent.width < parent.height ? parent.width : parent.height
    	height: width
    	radius: width * 0.5
    	border.width: parent.borderSize
    	border.color: parent.borderColor
    	color: parent.color
    }
}