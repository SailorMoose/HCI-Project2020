#include "annotationmodel.h"

AnnotationModel::AnnotationModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QModelIndex AnnotationModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent)){
        return QModelIndex();
    }
    Annotation* child = rootTier->getData().at(row);
    return createIndex(row, column, child);
}

int AnnotationModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return rootTier->getData().count();
}

int AnnotationModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
    return 3;
}

QVariant AnnotationModel::data(const QModelIndex &index, int role) const
{
    if(role!=Qt::DisplayRole){
        return QVariant();
    }
    if (!index.isValid())
        return QVariant();

    if(index.row()>rootTier->getData().size()){
        return QVariant();
    }
    switch (index.column()) {
        case 0:
            return rootTier->getData().at(index.row())->text();
        case 1:
            return rootTier->getData().at(index.row())->startpos();
        case 3:
            return rootTier->getData().at(index.row())->endpos();
        default:
            return QVariant();
    }
}

void AnnotationModel::addAnnotation(qlonglong start, qlonglong end, const QString& text){
    beginInsertRows(*root,rootTier->getData().count(),rootTier->getData().count());
    rootTier->addAnnotation(start,end, text);
    endInsertRows();
}

bool AnnotationModel::setRoot(QModelIndex &parent) {
    if(!parent.isValid()){
        return false;
    }
    beginResetModel();
    root = &parent;
    rootTier = static_cast<Tier*>(parent.internalPointer());
    endResetModel();
    std::cout << "Hej" << std::endl;
    return true;
}
