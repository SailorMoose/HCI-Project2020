import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtMultimedia 5.15
import QtQuick.Templates 2.15
import QtQuick.Extras 1.4
import QtQuick.Dialogs.qml 1.0
import QtQuick.Scene2D 2.9
import QtQuick.Shapes 1.14

ColumnLayout {
    id: mainWindow
    width: 1010
    height: 1010
    anchors.fill: parent

    GroupBox {
        id: mediaGroup
        width: 200
        height: 200
        Layout.fillHeight: true
        Layout.fillWidth: true
        title: qsTr("Media Group")


        MediaPlayer {
            id: mediaPlayer
            source: "media.mp4"
        }

        GridLayout {
            id: gridLayout
            anchors.fill: parent

            VideoPlayerPrototype {
                id: videoPlayerPrototype
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle
                width: 200
                height: 200
                color: "#ffffff"
                Layout.fillWidth: true
            }

        }
    }

    GroupBox {
        id: segmentGroup
        width: 200
        height: 200
        Layout.fillHeight: false
        Layout.fillWidth: true
        title: qsTr("SegmentationGroup")
    }
}

/*##^##
Designer {
    D{i:4;annotation:"1 //;;// Video Player //;;// Rasmus Olstedt //;;// <!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html> //;;// 1607724270";customId:"VideoPlayer"}
}
##^##*/
