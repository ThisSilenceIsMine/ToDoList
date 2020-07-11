#ifndef TODOLISTMODEL_H
#define TODOLISTMODEL_H

#include <QAbstractListModel>

class ToDoList;

class ToDoListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ToDoList *list READ list WRITE setList)
public:
    explicit ToDoListModel(QObject *parent = nullptr);
    enum {
        DoneRole = Qt::UserRole + 1,
        DescriptionRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QHash<int, QByteArray> roleNames() const override;

    ToDoList *list() const;
    void setList(ToDoList *list);

private:
    // QAbstractItemModel interface

    ToDoList *mList;

};

#endif // TODOLISTMODEL_H
