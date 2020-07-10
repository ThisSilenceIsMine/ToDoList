#include "todolistmodel.h"
#include "todolist.h"

ToDoListModel::ToDoListModel(QObject *parent)
    : QAbstractListModel(parent),
      mList(nullptr)
{
}

int ToDoListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    // FIXME: Implement me!
    return 100;
}

QVariant ToDoListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    ToDoItem item = mList->items().at(i);
    switch (role) {

    case DoneRole:
        return QVariant();

    case DescriptionRole:
        return QVariant();
    }
    // FIXME: Implement me!
    return QVariant();
}

bool ToDoListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ToDoListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}


QHash<int, QByteArray> ToDoListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescriptionRole] = "description";

    return names;
}

ToDoList *ToDoListModel::list() const
{
    return mList;
}

void ToDoListModel::setList(ToDoList *list)
{
    beginResetModel();

    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList) {
        connect(mList, &ToDoList::preItemAppended, this, [=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex{},index,index);
        });
        connect(mList, &ToDoList::postItemAppended, this, [=](){
           endInsertRows();
        });

        connect(mList, &ToDoList::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex{},index,index);
        });
        connect(mList, &ToDoList::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    }

    endResetModel();
}



ToDoList *ToDoListModel::getList() const
{
    return list;
}

void ToDoListModel::setList(ToDoList *value)
{
    list = value;
}
