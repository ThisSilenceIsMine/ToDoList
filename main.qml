import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 375
    height: 600
    title: qsTr("To-Do List")

    ToDoList {
        width: parent.width - 5
        height: parent.height - 5
        anchors.fill: parent
    }
}
