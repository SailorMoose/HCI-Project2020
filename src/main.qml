/*
 * Copyright 2021 - Rasmus Olstedt, Kjell Engehjelm, Daniel Malm
 *
 * This file is part of HCI-Project2020
 *
 * HCI-Project2020 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * */

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
