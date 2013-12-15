import QtQuick 2.2
import QtQuick.Particles 2.0
import "../"

Item {
    property bool done: true
    property string mainFile: ""
    property bool error: true

    FontLoader {
        id: iconFont
        source: "../../Fonts/typicons.ttf"
    }

    function startMixxx(mainQmlFile) {
        mainFile = Qt.resolvedUrl("../../Application/" + mainQmlFile);
        console.log("QML Load: " + mainFile);
        mixxxLoader.source = mainFile;
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
        id: mixxxConnection
        target: mixxxLoader.item
        onMixxxReady: {
            console.log("onMixxxReady");
            unlock();
        }
    }
    
    Connections {
        id: splashConnection
        target: splashLoader.item
        onTimeout: { 
            console.log("onTimeout");
            unlock();
        }
    }
    
    function unlock() {
        console.log("unlock");
        if(done) {
            splashLoader.source = "";
            mixxxConnection.target = null;
            splashConnection.target = null;
        }
        
        done = true;
    }

    function reloadUI() {
        mixxxLoader.source = "";
        splashLoader.source = "";
        mixxxConnection.target = null;
        splashConnection.target = null;
        console.log("Reload UI");
        MixxxTools.clearComponentCache();
        console.log("QML Load: " + mainFile);
        mixxxLoader.source = mainFile;
        mixxxLoader.active = true;
    }

    Item {
        id: errorView

        anchors.fill: parent
        visible: mixxxLoader.status == Loader.Error

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
                    text: error ? "" : ""
                }
            }
            Emitter {
                anchors.fill: parent
                size: 128
            }
        }

        Text {
            color: Theme.Colors.Red
            opacity: 0.2
            font.family: iconFont.name
            font.pointSize: 512
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: error ? "" : ""
        }

        Text {
            color: Theme.Colors.Red
            font.pointSize: 32
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Mixxx User Interface Crashed"
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
                color: Theme.Current.ContentSecondary
                font.pointSize: 16
                text: "Reload User Interface"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: reloadUI();
            }
        }
    }
}
