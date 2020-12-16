import QtQuick 2.15
//import QtMultimedia 5.15 as /*QtMultimedia*/
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtAV 1.7
import QtQuick.Dialogs 1.3

//import AsemanQml.Base 2.0 as AsBase
Item {
    id: mainWidget
    anchors.fill: parent
    width: 1280
    height: 800

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent

        Video {
            id: mediaPlayer
            Layout.fillHeight: true
            Layout.fillWidth: true
            subtitleText.renderType: Text.NativeRendering
            autoLoad: true
            volume: volumeSlider.value
            playbackRate: comboBox.currentText.valueOf()
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
                onMoved: mediaPlayer.seek(value)
            }

            ToolBar {
                id: toolBar
                width: 360
                position: ToolBar.Footer
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                RowLayout {
                    anchors.fill: parent
                    Layout.bottomMargin: 5
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                    ComboBox {
                        id: comboBox
                        width: 60
                        opacity: 1
                        flat: true
                        Layout.fillWidth: true
                        Layout.maximumWidth: 60
                        font.pointSize: 9
                        currentIndex: 3
                        Layout.maximumHeight: 36

                        model: ListModel {

                            ListElement {
                                text: "0.25"
                            }
                            ListElement {
                                text: "0.50"
                            }
                            ListElement {
                                text: "0.75"
                            }
                            ListElement {
                                text: "1"
                            }
                        }
                    }

                    ToolSeparator {
                        id: toolSeparator1
                    }

                    Slider {
                        id: volumeSlider
                        visible: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        value: mediaPlayer.volume
                    }

                    ToolSeparator {
                        id: toolSeparator
                    }

                    /* Go back one frame*/
                    ToolButton {
                        id: frameBackButton
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/BackFramIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(mediaPlayer.position - 1)
                    }
                    /*Seek start*/
                    ToolButton {
                        id: ssButton
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/BackToStarIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(0)
                    }

                    /*Seek -30s*/
                    ToolButton {
                        id: sm30Button
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/Back30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.seek(
                                       mediaPlayer.position - 30000)
                    }

                    /* Play and Pause*/
                    ToolButton {
                        id: playButton
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        text: "Play"
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/PlayIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: mediaPlayer.playbackState
                                   == MediaPlayer.PlayingState ? mediaPlayer.pause(
                                                                     ) : mediaPlayer.play()
                        states: [
                            State {
                                name: "Playing"

                                PropertyChanges {
                                    target: playButton
                                    icon.source: "../resources/PauseIcon.svg"
                                }
                            },
                            State {
                                name: "Paused"

                                PropertyChanges {
                                    target: playButton
                                    icon.source: "../resources/PlayIcon.svg"
                                }
                            }
                        ]
                    }

                    /*Seek +30s*/
                    ToolButton {
                        id: sp30Button
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        icon.source: "../resources/Forward30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        display: AbstractButton.IconOnly
                        onClicked: mediaPlayer.seek(
                                       mediaPlayer.position + 30000)
                    }

                    /*Seek End*/
                    ToolButton {
                        id: toEndButton
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/ToEndIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                        onClicked: {
                            mediaPlayer.seek(mediaPlayer.duration)
                            mediaPlayer.pause()
                        }
                    }

                    /*Go forward one millisec, smallest we can go as position is in millisec*/
                    ToolButton {
                        id: frameForwardButton
                        Layout.maximumHeight: 36
                        Layout.maximumWidth: 36
                        display: AbstractButton.IconOnly
                        icon.source: "../resources/ForwardFrameIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
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
