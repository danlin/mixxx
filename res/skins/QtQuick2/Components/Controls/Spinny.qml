import QtQuick 2.2
import Mixxx 1.0
import "../"

Item {

    property real angle : 0;

    MixxxEngineSource on angle { configKey: "[Channel1],playposition" }

	Rectangle {
        rotation: parent.angle * 360
    	width: parent.width < parent.height ? parent.width : parent.height
    	height: width
    	color: Theme.Current.ContentPrimary
    	border.color: Theme.Current.ContentEmphasized
    	border.width: 10
    	radius: width * 0.5
    	Rectangle {
    		anchors.horizontalCenter: parent.horizontalCenter
    		height: parent.width / 2
    		width: 10
    		color: "black"
    	}
    	Rectangle {
    		width: 20
    		height: width
    		anchors.horizontalCenter: parent.horizontalCenter
    		anchors.verticalCenter: parent.verticalCenter
    		color: Theme.Current.ContentEmphasized
    		radius: width * 0.5
    	}
	}
}
