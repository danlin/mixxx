import QtQuick 1.1
import "Engine.js" as Engine
import "../Controls/Mixxx"

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
        MixxxToolbar {
            id: mixxxToolbar
            onHideMixer: { Engine.hideMixer(); }
	  	}
        MixxxDeckView {
            id: mixxxDeckView
        }
    }
}
