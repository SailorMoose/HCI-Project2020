import QtQuick 2.0
import QtMultimedia 5.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11


Item {

    id: mainWidget

    ColumnLayout{
        id: mainColumn
        anchors.fill: parent

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
            id: mainItem

            MediaPlayer {
                id: mediaPlayer
                source: "media.mp4"
                onPlaying: playButton.visible = false
            }

            VideoOutput {
                id: videoOutput
                anchors.fill: parent
                source: mediaPlayer
            }

            MouseArea{
                id: mouseArea
                anchors.fill: parent
                onPressed: mediaPlayer.play()
            }

        }

        RowLayout{

            ProgressBar {
                id: videoProgressBar
                Layout.alignment: Qt.AlignLeft | Qt.AlignBaseline
                value: mediaPlayer.position
                to: mediaPlayer.duration
                Layout.fillWidth: true

            }
            Button{
                id: playButton
                text: "Play"
                onClicked: function(_play) { if ( mediaPlayer.playbackState ) mediaPlayer.play(); else mediaPlayer.pause();}

            }

        }


    }

}


//Item {
//    id: mainItem

//    MediaPlayer {
//        id: mediaPlayer
//        source: "media.mp4"
//    }

//    VideoOutput {
//        id: videoOutput
//        anchors.fill: parent
//        source: mediaPlayer
//    }

//    MouseArea{
//        id: mouseArea
//        anchors.fill: parent
//        onPressed: mediaPlayer.play()
//    }

//}

/*##^##
Designer {
    D{i:0;autoSize:true;height:0;width:0}
}
##^##*/
