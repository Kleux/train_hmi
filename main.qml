import QtQuick 2.9
import QtQuick.Window 2.2
//import com.Konnect 1.0

Window {
    id: bootscreen
    visible: true
    width: 800
    height: 400
    title: qsTr("HOT interface")




    BorderImage {
        id: borderImage
        x: 0
        y: 0
        width: 800
        height: 400
        source: "Logo.png"
    }
    Timer {
           interval: 5000; running: true; repeat: true
           onTriggered:time.source="defscreen.qml";

       }
           Timer {
                  interval: 5000; running: true; repeat: true
                  onTriggered:bootscreen.close()

              }
        Loader{
            id:time;
            anchors.fill: parent;
        }


}



