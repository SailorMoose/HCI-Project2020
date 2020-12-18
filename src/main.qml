import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.11
import QtQuick.Templates 2.15
import QtQuick.Extras 1.4
import QtQuick.Dialogs.qml 1.0
import QtQuick.Scene2D 2.9
import QtQuick.Shapes 1.14

ApplicationWindow {
    width: 1010
    height: 900
    visible: true

    ColumnLayout {
        id: mainWindow
        width: 1010
        height: 900

        GroupBox {
            id: mediaGroup
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
            Layout.fillHeight: false
            Layout.fillWidth: true
            title: qsTr("SegmentationGroup")
        }
    }
}