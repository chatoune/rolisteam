import QtQuick 2.0
import QtQuick 2.4
import QtQuick.Controls 2.0

Rectangle {
    id:root
    property string text: ""
    property alias currentIndex : selectvalues.currentIndex
    property alias currentText: selectvalues.currentText
    property alias count: selectvalues.count
    property alias itemDelegate: selectvalues.delegate
    property alias combo: selectvalues
    property alias indicator: selectvalues.indicator


    property color textColor:"black"
    property int hAlign: 0
    property int vAlign: 0
    property bool readOnly: false

    property alias availableValues: selectvalues.model
    property bool clippedText: false

    ComboBox {
        id: selectvalues
        anchors.fill: parent
        enabled: !root.readOnly
        onCountChanged: {
            currentIndex=selectvalues.find(root.text)
        }
    }
    onTextChanged: {
        if(selectvalues.count>0)
        {
            currentIndex=selectvalues.find(text)
        }
    }
}

