#include "todolist.h"

ToDoList::ToDoList(QObject *parent) : QObject(parent)
{

}

bool ToDoList::setItemAt(int index, const ToDoItem &item)
{
    if(index < 0 || index >= mItems.size())
        return false;

    const ToDoItem &oldItem = mItems.at(index);

    if(item.done == oldItem.done || item.description == oldItem.description)
        return false;

    mItems[index] = item;
    return true;
}

QVector<ToDoItem> ToDoList::items() const
{
    return mItems;
}

void ToDoList::appendItem()
{
    emit preItemAppended();

    ToDoItem item{false, QStringLiteral("")};
    mItems.append(item);

    emit postItemAppended();
}

void ToDoList::removeCompletedItems()
{
    for(int i = 0; i < mItems.size(); ) {
        if(mItems.at(i).done == true) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
