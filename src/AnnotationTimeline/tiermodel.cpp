#include <QInputDialog>
#include "tiermodel.h"

TierModel::TierModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    root = new Tier(tr("Tier"),nullptr);

}

TierModel::~TierModel(){
    delete root;
}

QModelIndex TierModel::index(int row, int column, const QModelIndex &parent) const{
    if(!hasIndex(row,column,parent)){
        return QModelIndex();
    }

    Tier* parentTier;
    if(!parent.isValid()){
        parentTier = root;
    }
    else{
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }
    Tier* childTier = parentTier->getChildAt(row);
    if(childTier){
        return createIndex(row,column,childTier);
    }
    return QModelIndex();
}

QModelIndex TierModel::parent(const QModelIndex &child) const
{
    if(!child.isValid()){
        return QModelIndex();
    }

    Tier* childTier = static_cast<Tier*>(child.internalPointer());
    Tier* parentTier = childTier->getParent();

    if(parentTier == root){
        return QModelIndex();
    }

    return createIndex(parentTier->parentPos(),0,parentTier);
}

bool TierModel::addTier(const QModelIndex &parent, QString title)
{
//    if(!parent.isValid()){
//        return false;
//    }
    Tier* parentTier;
    if(!parent.isValid()){
        parentTier = root;
    }
    else{
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }
    beginInsertRows(parent,parentTier->childCount(), parentTier->childCount());
    parentTier->appendChild(new Tier(title,parentTier));
    endInsertRows();
    return true;
}

bool TierModel::removeTier(int row, const QModelIndex &parent)
{
    Tier* parentTier;
    if(!parent.isValid()){
        parentTier = root;
    }
    else{
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }
    beginRemoveRows(parent, row, row);
    parentTier->removeChildAt(row);
    endRemoveRows();
    return true;
}

QVariant TierModel::data(const QModelIndex &index, int role) const
{
    if(role!=Qt::DisplayRole){
        return QVariant();
    }
    Tier *tier = static_cast<Tier *>(index.internalPointer());
    if(index.column()==0) {
        return tier->getTitle();
    }
    return QVariant();
}

int TierModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column()>0){
        return 0;
    }

    Tier* parentTier;
    if(!parent.isValid()){
        parentTier = root;
    }else{
        parentTier = static_cast<Tier*>(parent.internalPointer());
    }

    return parentTier->childCount();
}

int TierModel::columnCount(const QModelIndex &parent) const{
    return 1;
}

QVariant TierModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
            return root->getTitle();

        return QVariant();
}


QVector<Annotation*> TierModel::getAnnotations(const QModelIndex &parent){

    if(!parent.isValid()){
        return QVector<Annotation*>();
    }

    Tier *parentTier = static_cast<Tier*>(parent.internalPointer());
    return parentTier->getData();
}





