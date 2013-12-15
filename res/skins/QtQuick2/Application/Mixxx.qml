import QtQuick 2.0
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0
import "../Components"

Item {
    id: mixxx
    anchors.fill: parent
    signal mixxxReady();

    function init () {
        Engine.init();
    }

	Component.onCompleted: {
        console.log("Mixxx Ready")
        mixxx.mixxxReady();
    }
    
    Rectangle {
        id: background
        color: Theme.Current.Background
        anchors.fill: parent
        Connections {
            target: MixxxEngine
            onMixxxEvent: {
                if (eventKey == ("[Channel1],beat_active")) {
                    if (value) {
                        background.color = "#fdf6e3";
                    } else {
                        background.color = "#002b36";
                    }
                }
            }
        }
        Button {
            x: 100
            y: 100
            id: testButton
            text: "Test"
            Connections {
                target: MixxxEngine
                onMixxxEvent: {
                    if (eventKey == ("[Channel1],VuMeter")) {
                        console.log(value);
                        if (value) {
                            testButton.x = value * 100;
                        }
                    }
                }
            }
            onClicked: {
                dadssakdakfa
            }
        }
    }
}
