import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }


    Rectangle {
        width: 100; height: 100
        color: "red"

        SequentialAnimation on color {
            ColorAnimation { to: "yellow"; duration: 1000 }
            ColorAnimation { to: "blue"; duration: 1000 }
            ColorAnimation { to: "green"; duration: 1000 }
            ColorAnimation { to: "pink"; duration: 1000 }
        }
    }

    Rectangle {
        x:400
        width: 75; height: 75
        id: button
        state: "RELEASED"

        MouseArea {
            anchors.fill: parent
            onPressed: button.state = "PRESSED"
            onReleased: button.state = "RELEASED"
        }

        states: [
            State {
                name: "PRESSED"
                PropertyChanges { target: button; color: "lightblue"}
            },
            State {
                name: "RELEASED"
                PropertyChanges { target: button; color: "lightsteelblue"}
            }
        ]

        transitions: [
            Transition {
                from: "PRESSED"
                to: "RELEASED"
                ColorAnimation { target: button; duration: 100}
            },
            Transition {
                from: "RELEASED"
                to: "PRESSED"
                ColorAnimation { target: button; duration: 100}
            }
        ]
    }

    Rectangle {
        id: banner
        y: 200
        width: 150; height: 100; border.color: "black"

        Column {
            anchors.centerIn: parent
            Text {
                id: code
                text: "Code less."
                opacity: 0.01
            }
            Text {
                id: create
                text: "Create more."
                opacity: 0.01
            }
            Text {
                id: deploy
                text: "Deploy everywhere."
                opacity: 0.01
            }
        }

        MouseArea {
            anchors.fill: parent
            onPressed: playbanner.start()
        }

        SequentialAnimation {
            id: playbanner
            running: false
            NumberAnimation { target: code; property: "opacity"; to: 1.0; duration: 200}
            NumberAnimation { target: create; property: "opacity"; to: 1.0; duration: 200}
            NumberAnimation { target: deploy; property: "opacity"; to: 1.0; duration: 200}
        }
    }


//    Rectangle{
//        width: 256; height: 256
//        color: "red"
//        Text {
//            id: some_text
//            text: qsTr("Some text")
//        }
//    }

//    Rectangle{
//        x: 300
//        width: 256; height: 256
//        color: "lightblue"
//        Text {
//            id: some_text2
//            text: qsTr("Some text 2")
//            scale: 2
//        }
//    }

//    Rectangle {
//         id: flashingblob
//         width: 75; height: 75
//         color: "blue"
//         opacity: 1.0

//         MouseArea {
//             anchors.fill: parent
//             onClicked: {
//                 animateColor.start()
//                 animateOpacity.start()
//             }
//         }

//         PropertyAnimation {id: animateColor; target: flashingblob; properties: "color"; to: "green"; duration: 100}

//         NumberAnimation {
//             id: animateOpacity
//             target: flashingblob
//             properties: "opacity"
//             from: 0.99
//             to: 1.0
//             loops: Animation.Infinite
//             easing {type: Easing.OutBack; overshoot: 500}
//        }
//     }

}
