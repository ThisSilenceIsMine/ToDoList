import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import ToDo 1.0

ColumnLayout {
    id: root
    height: 800
    width: 370
    Frame {
        Layout.fillWidth: true

        ListView {
            implicitHeight: root.height - buttonsRow.height - 50
            implicitWidth: 250

            clip: true
            spacing: 15

            model: ToDoListModel {
                list: toDoList
            }

            delegate: RowLayout {
                width: parent.width
                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }
                TextField {
                    text: model.description
                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }

            }
        }
    }
    RowLayout {
        id: buttonsRow
        Button {
            text: qsTr("Add new item")
            onClicked: toDoList.appendItem();
            Layout.fillWidth: true
        }
        Button {
            text: qsTr("Remove completed")
            onClicked: toDoList.removeCompletedItems();

        }
    }
}
