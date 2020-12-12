import QtQuick 2.15
//import QtMultimedia 5.15 as /*QtMultimedia*/
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtAV 1.7

//import AsemanQml.Base 2.0 as AsBase
Item {

    id: mainWidget

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent

        Video {
            id: mediaPlayer
            Layout.fillHeight: true
            Layout.fillWidth: true
            source: "../resources/media.mp4"
            autoLoad: true
            onPlaying: {
                playButton.text = "Pause"
                playButton.icon.source = "../resources/PauseIcon.svg"
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
            onPaused: {
                playButton.text = "Play"
                playButton.icon.source = "../resources/PlayIcon.svg"
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onPressed: mediaPlayer.play()
            }
        }

        ColumnLayout {
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.fillWidth: true

            Slider {
                id: videoProgressBar
                snapMode: Slider.SnapOnRelease
                value: mediaPlayer.position
                to: mediaPlayer.duration
                Layout.fillWidth: true
                onMoved: mediaPlayer.seek(value)
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                Button {
                    id: frameBackButton
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    display: AbstractButton.IconOnly
                    icon.source: "../resources/BackFramIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                }

                Button {
                    id: ssButton
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    display: AbstractButton.IconOnly
                    icon.source: "../resources/BackToStarIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                }

                Button {
                    id: sm30Button
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    display: AbstractButton.IconOnly
                    icon.source: "../resources/Back30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                }

                Button {
                    id: playButton
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    text: "Play"
                    flat: true
                    display: AbstractButton.IconOnly
                    icon.name: "playButtonIcon"
                    icon.source: "../resources/PlayIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                    onClicked: mediaPlayer.playbackState
                               == MediaPlayer.PlayingState ? mediaPlayer.pause(
                                                                 ) : mediaPlayer.play()
                }

                Button {
                    id: sp30Button
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    icon.source: "../resources/Forward30Icon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                    display: AbstractButton.IconOnly
                }

                Button {
                    id: toEndButton
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    display: AbstractButton.IconOnly
                    icon.source: "../resources/ToEndIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                }

                Button {
                    id: frameForwardButton
                    Layout.maximumHeight: 36
                    Layout.maximumWidth: 36
                    display: AbstractButton.IconOnly
                    icon.source: "../resources/ForwardFrameIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
