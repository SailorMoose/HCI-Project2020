/*
 * Copyright 2021 - Rasmus Olstedt, Kjell Engehjelm, Daniel Malm
 *
 * This file is part of HCI-Project2020
 *
 * HCI-Project2020 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * */

#include "annotationmodel.h"

AnnotationModel::AnnotationModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    root=nullptr;
}

QModelIndex AnnotationModel::index(int row, int column, const QModelIndex &parent) const
{
//    if(!hasIndex(row,column,parent)){
//        return QModelIndex();
//    }
    if(!parent.isValid()){
        Annotation* child = root->getData().at(row);
        if(child){
            return createIndex(row, column, child);
        }
    }
    return QModelIndex();
}

int AnnotationModel::rowCount(const QModelIndex &parent) const
{
    if(root){
        return root->getData().count();
    }
    return 0;
}

int AnnotationModel::columnCount(const QModelIndex &parent) const
{
    if (root){
        return 3;
    }
    return 0;

}

QVariant AnnotationModel::data(const QModelIndex &index, int role) const
{
    if(role!=Qt::DisplayRole){
        return QVariant();
    }
    switch (index.column()) {
        case 0:
            return root->getData().at(index.row())->text();
        case 1:
            return root->getData().at(index.row())->startpos();
        case 2:
            return root->getData().at(index.row())->endpos();
        default:
            return QVariant();
    }
}

QVariant AnnotationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section) {
            case 0:
                return QString("Text");
            case 1:
                return QString("Start Pos");
            case 2:
                return QString("End Pos");
        }
    }
    return QVariant();
}

void AnnotationModel::addAnnotation(qlonglong start, qlonglong end, const QString& text){
    beginInsertRows(QModelIndex(),root->getData().count(),root->getData().count());
    root->addAnnotation(start,end, text);
    endInsertRows();
}

bool AnnotationModel::setRoot(QModelIndex &parent) {
    if(!parent.isValid()){
        return false;
    }

    beginResetModel();
    root = static_cast<Tier*>(parent.internalPointer());
    endResetModel();
    return true;
}
