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
        property var mixxxValue: 0
        Connections {
            onMixxxValueChanged: {
                if (mixxxValue == 1) {
                    if (value) {
                        background.color = "#fdf6e3";
                    } else {
                        background.color = "#002b36";
                    }
                }
            }
        }

        MixxxControlObject on mixxxValue { configKey: "[Channel1],beat_active" }

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
            text: "Clear List"
            onClicked: {
                MixxxWarnings.removeDuplicates();
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

        TableView {
            x: 300
            y: 300
            width: 400
            height: 200
            model: MixxxWarnings
            TableViewColumn {
                        title: "Title"
                        width: 120
                    }
        }
    }
}
