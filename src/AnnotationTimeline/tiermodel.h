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

#ifndef TIERMODEL_H
#define TIERMODEL_H

#include <QAbstractItemModel>
#include <QDialog>
#include "Tier.h"

class TierModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    //Constructor and deconstructor
    explicit TierModel(QObject *parent = nullptr);
    ~TierModel() override;

    //Return index for the view
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    //Return the index of parent
    QModelIndex parent(const QModelIndex &child) const override;

    //add and remove Tiers
    bool addTier(const QModelIndex &parent, QString title);
    bool removeTier(int row, const QModelIndex &parent);

    //Basic grabbing of data, should be changed to return both title and annotations
    QVariant data(const QModelIndex &index, int role) const override;

   //Amount of rows and amount of columns(data) of a tier
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    //Get Header
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;



private:
    Tier *root;

    QVector<Annotation *> getAnnotations(const QModelIndex &parent);
};

#endif // TIERMODEL_H
