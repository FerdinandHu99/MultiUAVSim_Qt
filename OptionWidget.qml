import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.0
import MultiUAVSim 1.0

Item {
    id: _root
    anchors.fill: parent

    Rectangle {
        id: background
        color: "#bac3a9"
        anchors.fill: parent
    }
    Rectangle {
        id: rectangle_filePath
        x: 119
        y: 159
        width: 269
        height: 25
        color: "#ffffff"

        Label {
            id: label_filePath
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Button {
        id: button_chose
        x: 387
        y: 159
        width: 30
        height: 25
        text: qsTr("...")
        font.pointSize: 9
        font.bold: true
        onClicked: {
            fileDialog.open()
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: "file:///E:/UE_Projects/MultiUAVSim/Intermediate/ProjectFiles"
        onAccepted: {
            var choseFileUrl = fileDialog.fileUrl.toString()
            choseFileUrl = choseFileUrl.substring("file:///".length)
            label_filePath.text = choseFileUrl
            MultiUAVSim.settingsManage.setSettingsFilePath(choseFileUrl);
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false
    }

    Button {
        id: button_read
        x: 130
        y: 213
        width: 79
        height: 24
        text: qsTr("read")
        onClicked: {
            var simMode = MultiUAVSim.settingsManage.readKeyValue("SimMode");
            console.log(simMode)
        }
    }

    Button {
        id: button_write
        x: 227
        y: 213
        width: 84
        height: 24
        text: qsTr("write")
        onClicked: {
            var simMode = MultiUAVSim.settingsManage.writeKeyValue("SimMode", "Car");
        }
    }

    Button {
        id: button_add
        x: 328
        y: 213
        width: 84
        height: 24
        text: qsTr("add")
        onClicked: {
            var newUAVData = {
                "VehicleType": "SimpleFlight",
                "X": 5,
                "Y": 0,
                "Z": 0
            }
            MultiUAVSim.settingsManage.addNewUAV("UAV1", newUAVData);
        }
    }
}
