import QtQuick 2.2
import QtQuick.Particles 2.0
import "../"

Item {
    id: mixxxApplication
    QtObject {
        id: internal        
    }

    property bool loadingDone: true
    property string currentQmlFile: ""
    property bool errorVisible: false

    property bool holdOnWarnings: false;

    // load icon font
    FontLoader {
        id: iconFont
        source: "../../Fonts/typicons.ttf"
    }

    Connections {
        target: MixxxTools
        onWarning: {
            if (mixxxApplication.holdOnWarnings) {
                if (!mixxxErrorScreen.visible) {
                    mixxxErrorScreen.isWarning = true;
                    mixxxApplication.errorVisible = true;
                }
            }
        }
    }

    function startMixxx(mainQmlFile) {
        mixxxApplication.currentQmlFile = Qt.resolvedUrl("../../Application/" + mainQmlFile);
        console.log("[QML] Load: " + mixxxApplication.currentQmlFile);
        mixxxLoader.source = mixxxApplication.currentQmlFile;
        splashLoader.active = true;
    }

    // main qml app
    Loader {
        id: mixxxLoader
        anchors.fill: parent
        active: false
    }
    
    // splash screen
    Loader {
        id: splashLoader
        anchors.fill: parent
        source: "Splash.qml"
        active: false
        onLoaded: mixxxLoader.active = true
    }
    
    Connections {
        id: splashConnection
        target: splashLoader.item
        onTimeout: { 
            unlock();
        }
    }
    
    function unlock() {
        if(mixxxApplication.loadingDone) {
            splashLoader.source = "";
            splashConnection.target = null;
        }
        
        mixxxApplication.loadingDone = true;
    }

    function reloadUI() {
        mixxxLoader.source = "";
        splashLoader.source = "";
        splashConnection.target = null;
        console.log("[QML] Reboot UI");
        MixxxTools.clearComponentCache();
        console.log("[QML] Load: " + mixxxApplication.currentQmlFile);
        mixxxLoader.source = mixxxApplication.currentQmlFile;
        mixxxLoader.active = true;
    }

    Item {
        id: mixxxErrorScreen

        property bool isWarning: false;
        property string errorMessage: "";

        anchors.fill: parent
        visible: mixxxLoader.status == Loader.Error || mixxxApplication.errorVisible

        Rectangle {
            color: Theme.Current.Background
            anchors.fill: parent
        }
            
        ParticleSystem {
            anchors.fill: parent
            ItemParticle {
                delegate: Text {
                    color: Theme.Current.BackgroundHighlights
                    font.family: iconFont.name
                    font.pointSize: 128
                    text: mixxxErrorScreen.isWarning ? Theme.Icon.warning_outline : Theme.Icon.warning
                }
            }
            Emitter {
                anchors.fill: parent
                size: 128
            }
        }

        Text {
            color: mixxxErrorScreen.isWarning ? Theme.Colors.Yellow : Theme.Colors.Red
            opacity: 0.2
            font.family: iconFont.name
            font.pointSize: 512
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: mixxxErrorScreen.isWarning ? Theme.Icon.warning_outline : Theme.Icon.warning
        }

        Text {
            color: mixxxErrorScreen.isWarning ? Theme.Colors.Yellow : Theme.Colors.Red
            font.pointSize: 32
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: mixxxErrorScreen.isWarning ? "Warning" : "Mixxx User Interface Crashed"
        }

        Rectangle {
            id: errorListContainer
            anchors.fill: parent
            color: "transparent"

            Component {
                id: contactDelegate
                Item {
                    width: parent.width
                    height: 40
                    Column {
                        Text { color: Theme.Current.ContentPrimary; text: '<b>Error:</b> ' + description }
                        Text { color: Theme.Current.ContentPrimary; text: '<b>File:</b> ' + url + ':'  + line + ':' + column }
                    }
                    
                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            errorListView.currentIndex = index
                        }
                    }
                }
            }

            ListView {
                id: errorListView
                anchors.fill: parent
                model: MixxxWarnings
                delegate: contactDelegate
                highlight: Rectangle { color: Theme.Current.BackgroundHighlights; }
                focus: true
            }
        }


        Rectangle {
            width: parent.width
            height: 20
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            color: Theme.Current.BackgroundHighlights
            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: Theme.Current.ContentPrimary
                font.pointSize: 16
                text: mixxxErrorScreen.isWarning ? "Continue" : "Reload User Interface"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: mixxxErrorScreen.isWarning ? mixxxApplication.errorVisible = false : reloadUI();
            }
        }
    }
}
