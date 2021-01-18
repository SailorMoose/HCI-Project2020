import QtQuick 2.15
import QtMultimedia 5.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3
import QtQuick.Controls.Material 2.12

//import QtAV 1.7
//import AsemanQml.MaterialIcons 2.0
Item {
    id: mainWidget
    //    Layout.fillHeight: true
    //    Layout.fillWidth: true
    width: 1280
    height: 800

//    visible: true
    anchors.fill: parent

    //    visible: true
    ColumnLayout {
        id: mainColumn
        anchors.fill: parent

        Video {
            id: mediaPlayer
            Layout.fillHeight: true
            Layout.fillWidth: true
            autoLoad: true
            volume: volumeSlider.value
            playbackRate: playBackDial.value.toPrecision(2)
            //            playbackRate: comboBox.currentText.valueOf()
            onPlaybackRateChanged: playbackRate == 1 ? muted = false : muted = true
            onPlaying: {
                playButton.state = "Playing"
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
            onPaused: {
                playButton.state = ""
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
            onStatusChanged: if (mediaPlayer.status == MediaPlayer.EndOfMedia)
                                 playButton.state = ""

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onPressed: mediaPlayer.status == MediaPlayer.NoMedia ? fileDialog.open(
                                                                           ) : mediaPlayer.playbackState == MediaPlayer.PlayingState ? mediaPlayer.pause() : mediaPlayer.play()
            }
        }

        ColumnLayout {
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.fillWidth: true

            Slider {
                id: videoProgressBar
                value: mediaPlayer.position
                to: mediaPlayer.duration
                Layout.fillWidth: true
                background: Rectangle {
                       x: videoProgressBar.leftPadding
                       y: videoProgressBar.topPadding + videoProgressBar.availableHeight / 2 - height / 2
                       implicitWidth: 200
                       implicitHeight: 4
                       width: videoProgressBar.availableWidth
                       height: implicitHeight
                       radius: 2
                       color: "#d5cfc0"
                       border.color: "#d5cfc0"

                       Rectangle {
                           width: videoProgressBar.visualPosition * parent.width
                           height: parent.height
                           color: "#FFD6D6"
                           radius: 2
                       }
                   }
                handle: Rectangle {
                        x: videoProgressBar.leftPadding + videoProgressBar.visualPosition * (videoProgressBar.availableWidth - width)
                        y: videoProgressBar.topPadding + videoProgressBar.availableHeight / 2 - height / 2
                        implicitWidth: 16
                        implicitHeight: 16
                        radius: 8
                        color: "#FFD6D6"

                    }
                onMoved: mediaPlayer.seek(value)
            }

            ToolBar {
                id: toolBar
                width: 360
                position: ToolBar.Footer
                Layout.alignment: Qt.AlignCenter | Qt.AlignVCenter

                RowLayout {
                    anchors.fill: parent
                    Layout.bottomMargin: 5
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                    Dial {
                        id: playBackDial
                        background: Rectangle {
                                x: playBackDial.width / 2 - width / 2
                                y: playBackDial.height / 2 - height / 2
                                width: 40
                                height: 40
                                color: "transparent"
                                radius: width / 2
                                border.color: "#FFD6D6"
                                opacity: playBackDial.enabled ? 1 : 0.3
                            }
                        handle: Rectangle {
                                id: handleItem
                                x: playBackDial.background.x + playBackDial.background.width / 2 - width / 2
                                y: playBackDial.background.y + playBackDial.background.height / 2 - height / 2
                                width: 12
                                height: 12
                                color: "#FFD6D6"
                                radius: 6
                                antialiasing: true
                                opacity: playBackDial.enabled ? 1 : 0.3
                                transform: [
                                    Translate {
                                        y: -Math.min(playBackDial.background.width, playBackDial.background.height) * 0.4 + handleItem.height / 2
                                    },
                                    Rotation {
                                        angle: playBackDial.angle
                                        origin.x: handleItem.width / 2
                                        origin.y: handleItem.height / 2
                                    }
                                ]
                            }
                        width: 60
                        opacity: 1
                        hoverEnabled: true
                        inputMode: Dial.Horizontal
                        wheelEnabled: true
                        snapMode: Dial.SnapAlways
                        stepSize: 0.1
                        value: mediaPlayer.playbackRate.toPrecision(2)
                        to: 2
                        //                        flat: true
                        Layout.fillWidth: true
                        Layout.maximumWidth: 65
                        //                        currentIndex: 3
                        Layout.maximumHeight: 40

                        Label {
                            id: playBackLabel
                            x: 18
                            y: -22
                            text: playBackDial.value.toPrecision(2)
                            anchors.verticalCenter: parent.verticalCenter
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.horizontalCenterOffset: 3
                            anchors.verticalCenterOffset: 5
                            anchors.horizontalCenter: parent.horizontalCenter
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                            font.pointSize: 8
                            font.family: "Courier"
                        }
                    }

                    ToolSeparator {
                        id: toolSeparator1
                    }

                    Slider {
                        id: volumeSlider
                        visible: true
                        background: Rectangle {
                               x: volumeSlider.leftPadding
                               y: volumeSlider.topPadding + volumeSlider.availableHeight / 2 - height / 2
                               implicitWidth: 200
                               implicitHeight: 4
                               width: volumeSlider.availableWidth
                               height: implicitHeight
                               radius: 2
                               color: "#d5cfc0"
                               border.color: "#d5cfc0"

                               Rectangle {
                                   width: volumeSlider.visualPosition * parent.width
                                   height: parent.height
                                   color: "#FFD6D6"
                                   radius: 2
                               }
                           }
                        handle: Rectangle {
                                x: volumeSlider.leftPadding + volumeSlider.visualPosition * (volumeSlider.availableWidth - width)
                                y: volumeSlider.topPadding + volumeSlider.availableHeight / 2 - height / 2
                                implicitWidth: 16
                                implicitHeight: 16
                                radius: 8
                                color: "#FFD6D6"
                            }
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        value: mediaPlayer.volume
                    }

                    ToolSeparator {
                        id: toolSeparator
                    }

                    /* Go back one frame*/
                    ToolButton {

                        id: frameBackButton
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/BackFramIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(mediaPlayer.position - 1)
                    }
                    /*Seek start*/
                    ToolButton {
                        id: ssButton
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/BackToStarIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(0)
                    }

                    /*Seek -30s*/
                    ToolButton {
                        id: sm30Button
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/Back30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(
                                       mediaPlayer.position - 30000)
                    }

                    /* Play and Pause*/
                    ToolButton {
                        id: playButton
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        text: "Play"
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/PlayIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.playbackState
                                   == MediaPlayer.PlayingState ? mediaPlayer.pause(
                                                                     ) : mediaPlayer.play()
                        states: [
                            State {
                                name: "Playing"

                                PropertyChanges {
                                    target: playButton
                                    icon.source: "qrc:/resources/PauseIcon.svg"
                                }
                            },
                            State {
                                name: "Paused"

                                PropertyChanges {
                                    target: playButton
                                    icon.source: "qrc:/resources/PlayIcon.svg"
                                }
                            }
                        ]
                    }

                    /*Seek +30s*/
                    ToolButton {
                        id: sp30Button
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        icon.source: "qrc:/resources/Forward30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        display: AbstractButton.IconOnly
                        onClicked: mediaPlayer.seek(
                                       mediaPlayer.position + 30000)
                    }

                    /*Seek End*/
                    ToolButton {
                        id: toEndButton
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/ToEndIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: {
                            mediaPlayer.seek(mediaPlayer.duration)
                            mediaPlayer.pause()
                        }
                    }

                    /*Go forward one millisec, smallest we can go as position is in millisec*/
                    ToolButton {
                        id: frameForwardButton
                        Layout.maximumHeight: 25
                        Layout.maximumWidth: 25
                        display: AbstractButton.IconOnly
                        icon.source: "qrc:/resources/ForwardFrameIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(mediaPlayer.position + 1)
                    }
                }
            }
        }
    }
    FileDialog {
        id: fileDialog
        folder: shortcuts.home
        title: "Choose video to load"
        nameFilters: ["Video files (*.mp4)"]
        onAccepted: mediaPlayer.source = fileUrl
    }
}
