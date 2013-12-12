import QtQuick 2.0
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
        onMixxxInitialized: {
            mixxx.init();
            mixxx.mixxxReady();
        }
    }
    
    Rectangle {
        id: background
        color: "#fdf6e3"
        anchors.fill: parent
        Rectangle {
            id: box
            color: "#2aa198"
            width: 100
            height: 200
        }
    }
}
