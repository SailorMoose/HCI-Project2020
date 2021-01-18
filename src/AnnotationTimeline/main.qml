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
