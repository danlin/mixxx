import QtQuick 2.0
import "../"

Item {
    id: splash
    signal timeout();
    
    MouseArea {
        anchors.fill: parent
    }
    
    Rectangle {
        color: "#000000"
        anchors.fill: parent
    }
  
    Image {
        source: "../../Images/Splash/Logo.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
  
    Timer {
        running: true
        interval: 1500
        onTriggered: splash.timeout();
    }
}
  
    
