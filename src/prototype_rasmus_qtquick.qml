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

        GridLayout {
            id: gridLayout
            anchors.fill: parent

            VideoPlayerPrototype {
                id: videoPlayerPrototype
                Layout.fillHeight: true
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


