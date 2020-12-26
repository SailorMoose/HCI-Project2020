import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: root
    width: 1080
    height: 500
    visible: true


    RowLayout {
        id: rootLayout
        anchors.fill: parent

        ColumnLayout {
            id: tree
            width: 100
            height: 100

            Rectangle{
                color: "#ad0606"
                Layout.fillHeight: true
                Layout.fillWidth: true

            }

        }

        ColumnLayout {
            id: annotations
            width: 100
            height: 100
            Layout.fillWidth: true
            Layout.fillHeight: true

        }
    }
}
