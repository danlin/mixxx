import QtQuick 1.1
import "Engine.js" as Engine

Item {
    id: mixxx
    anchors.fill: parent
    signal mixxxReady();

    function init () {
        Engine.init();
    }

	Connections {
		target: MixxxEngine
        onMixxxEvent: {
            Engine.onMixxxEvent(eventKey, value);
        }
    }
    
    Rectangle {
        id: background
        color: "#0c0e0e"
        anchors.fill: parent
    }
}
