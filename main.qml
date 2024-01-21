import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import MultiUAVSim 1.0

ApplicationWindow {
    width:          Math.min(250 * Screen.pixelDensity, Screen.width)
    height:         Math.min(150 * Screen.pixelDensity, Screen.height)
    visible:        true
    title:          qsTr("MultiUAVSim_Qt")
    Component.onCompleted: {
        console.log(width, height)
    }
    header: Item {
        height: 40
    }

    OptionWidget {

    }
}
