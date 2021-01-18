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

#ifndef ANNOTATIONMODEL_H
#define ANNOTATIONMODEL_H

#include <iostream>
#include <QAbstractItemModel>
#include "Annotation.h"
#include "Tier.h"

class AnnotationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AnnotationModel(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setRoot(QModelIndex &parent);

    void addAnnotation(qlonglong start, qlonglong end, const QString& text);

     QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    Tier* root;


};

#endif // ANNOTATIONMODEL_H
