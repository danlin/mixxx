import QtQuick 2.0
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0
import "../Components"
import Mixxx 1.0

Item {
    id: mixxx
    anchors.fill: parent
    signal mixxxReady();

	Component.onCompleted: {
        mixxx.mixxxReady();
    }
    
    Connections {
        target: MixxxEngine
        onMixxxEvent: {
            Engine.EventListener.onMixxxEvent(eventKey, value);
        }
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

        Rectangle {
            width: 400;
            height: 150;
            color: Theme.Current.BackgroundHighlights
            MixxxWaveform {
                anchors.fill: parent
            }
        }

        Button {
            x: 100
            y: 100
            id: testButton
            text: "Press for Warning"
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
                console.log("test");dasdsa
            }
        }

        Button {
            x: 300
            y: 100
            text: "Dump Warnings"
            onClicked: {
                console.log(MixxxTools.getWarnings());
            }
        }

        Button {
            x: 100
            y: 200
            text: "Reset Warnings"
            onClicked: {
                MixxxTools.clearWarnings();
            }
        }

        Button {
            x: 300
            y: 200
            text: "Enable Warning Screen"
            onClicked: {
                mixxxApplication.holdOnWarnings = true
            }
        }

        Button {
            x: 100
            y: 300
            text: "Reboot UI"
            onClicked: {
                mixxxApplication.reloadUI();
            }
        }

        Spinny {
            x: 300
            y: 300
            width: 200
            height: 200
        }
    }
}
