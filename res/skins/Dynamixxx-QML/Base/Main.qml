import QtQuick 1.1

Item {
    id: main
    property bool done: false

    Loader {
        id: mixxxLoader
        anchors.fill: parent
    }
    
    Loader {
        id: splashLoader
        anchors.fill: parent
        source: "Splash.qml"
        onLoaded: mixxxLoader.source = "Mixxx.qml"
    }
    
    Connections {
        id: mixxxConnection
        target: mixxxLoader.item
        onMixxxReady: unlock();
    }
    
    Connections {
        id: splashConnection
        target: splashLoader.item
        onTimeout: unlock();
    }
    
    function unlock() {
        //if(done) {
            MixxxEngine.setValue("[Library]", "visible", 1);
            splashLoader.source = "";
            mixxxConnection.target = null;
            splashConnection.target = null;
        //}
        
        //done = true;
    }
}
