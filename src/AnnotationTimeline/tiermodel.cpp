#include <QInputDialog>
#include "tiermodel.h"

TierModel::TierModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    root = new Tier(tr("Tier"));
}

//QVariant TierModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

bool TierModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QModelIndex TierModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent)){
        return QModelIndex();
    }

    Tier *parentTier;
    if (!parent.isValid()){
        parentTier = root;
    }
    else{
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }
    Tier *childTier = parentTier->child(row);
    if(childTier){
        return createIndex(row,column,childTier);
    }
    return QModelIndex();
}

QModelIndex TierModel::parent(const QModelIndex &index) const
{
    if (!index.isValid()){
        return QModelIndex();
    }

    Tier *childTier = static_cast<Tier*>(index.internalPointer());
    Tier *parentTier = childTier->parentTier();

    if(parentTier == root){
        return QModelIndex();
    }
    return createIndex(parentTier->row(),0, parentTier);

}

int TierModel::rowCount(const QModelIndex &parent) const
{
    Tier *parentTier;
    if (parent.column() > 0)
        return 0;

    if(!parent.isValid()){
        parentTier = root;
    }
    else {
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }
    return parentTier->childCount();
}

int TierModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()){
        return static_cast<Tier*>(parent.internalPointer())->columnCount();
    }
        return root->columnCount();

}

bool TierModel::hasChildren(const QModelIndex &parent) const
{
    if (!parent.isValid()){
        return false;
    }
    Tier *parentTier = static_cast<Tier*>(parent.internalPointer());
    if(parentTier->childCount() > 0){
        return true;
    }
    return false;
}

QVariant TierModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole){
        return QVariant();
    }

    Tier *tier = static_cast<Tier*>(index.internalPointer());
    return tier->data(index.column());
}

bool TierModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        Tier *tier = static_cast<Tier*>(index.internalPointer());
        tier->setData(index.column(), value);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TierModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool TierModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(!parent.isValid()){
        return false;
    }

    Tier * newTier = new Tier(tr("HEj"),static_cast<Tier*>(parent.internalPointer()));


    // Basic implementation of just appending on a new child
    beginInsertRows(parent, row, row + count - 1);
    Tier *parentTier = static_cast<Tier *>(parent.internalPointer());
    parentTier->appendChild(newTier);
    endInsertRows();
    return true;
}

bool TierModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    Tier *parentTier = static_cast<Tier*>(parent.internalPointer());
    beginInsertColumns(parent, column, column + count - 1);
    parentTier->addAnnotation();
    endInsertColumns();
    return true;
}

bool TierModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Tier *parentTier = static_cast<Tier*>(parent.internalPointer());
    beginRemoveRows(parent, row, row + count - 1);
    bool removed = parentTier->removeChild(parentTier->child(row));
    endRemoveRows();
    return removed;
}

bool TierModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    if(!parent.isValid()){
        return false;
    }
    Tier *parentTier = static_cast<Tier*>(parent.internalPointer());
    beginRemoveColumns(parent, column, column + count - 1);
    parentTier->removeAnnotation(column);
    endRemoveColumns();
    return true;
}

TierModel::~TierModel() {
    delete root;

}
