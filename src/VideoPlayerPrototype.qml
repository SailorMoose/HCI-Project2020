import QtQuick 2.15
import QtMultimedia 5.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Item {

    id: mainWidget

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent

        Video {
            id: mediaPlayer
            Layout.fillHeight: true
            Layout.fillWidth: true
            source: "media.mp4"
            onPlaying: {
                playButton.text = "Pause"
                playButtonIcon.source = "qrc://images/PauseIcon.svg"
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
            onPaused: {
                playButton.text = "Play"
                playButtonIcon.source = "qrc://images/PlayIcon.svg"
            } /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onPressed: mediaPlayer.play()
            }
        }
        RowLayout {
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.fillWidth: true

            Button {
                id: button2
                Layout.maximumHeight: 36
                Layout.maximumWidth: 36
                display: AbstractButton.IconOnly
            }

            Button {
                id: button
                Layout.maximumHeight: 36
                Layout.maximumWidth: 36
                display: AbstractButton.IconOnly
            }

            Button {
                id: playButton
                Layout.maximumHeight: 36
                Layout.maximumWidth: 36
                text: "Play"
                flat: true
                display: AbstractButton.IconOnly
                onClicked: mediaPlayer.playbackState
                           == MediaPlayer.PlayingState ? mediaPlayer.pause(
                                                             ) : mediaPlayer.play()
                Image {
                    id: playButtonIcon
                    source: "PlayIcon.svg" /*<a href='https://dryicons.com/free-icons/media-player-icons'> Icon by Dryicons </a>*/
                    sourceSize.height: playButton.height
                    sourceSize.width: playButton.width
                }
            }

            Button {
                id: button1
                Layout.maximumHeight: 36
                Layout.maximumWidth: 36
                display: AbstractButton.IconOnly
            }

            Button {
                id: button3
                Layout.maximumHeight: 36
                Layout.maximumWidth: 36
                display: AbstractButton.IconOnly
            }

            Slider {
                id: videoProgressBar
                value: mediaPlayer.position
                to: mediaPlayer.duration
                Layout.fillWidth: true
                onMoved: mediaPlayer.seek(value)
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

