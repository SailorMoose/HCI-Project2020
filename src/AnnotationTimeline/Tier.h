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

#ifndef HCI_PROJECT2020_TIER_H
#define HCI_PROJECT2020_TIER_H


#include <string>
#include <list>
#include <utility>
#include <QVariant>
#include "Annotation.h"


class Tier{

    //Possible QML integration
//    Q_OBJECT
//    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
//    Q_PROPERTY(QVector<QObject> annotations)

public:

    //Constructor and Deconstructor
    explicit Tier(QString title, Tier *parentTier = nullptr);
    ~Tier();

    //Get parent Tier
    Tier* getParent();

    //Get pos at parent
    int parentPos();

    //Get number of children
    int childCount();

    //Get child at possition
    Tier* getChildAt(int pos);

    //Append child
    void appendChild(Tier* child);

    //Insert child at
    void insertChild(Tier* child, int pos);

    //Remove child
    bool removeChild(Tier* child);
    void removeChildAt(int pos);

    //Get and set title
    void setTitle(QString title);
    QString getTitle();

    //Get list with annotations
    QVector<Annotation*> getData();

    void addAnnotation(qlonglong start, qlonglong end, QString text);



private:

    Tier* _parent;
    QString _title;
    QVector<Tier*> _childTiers;
    QVector<Annotation*> annotations;

};

//Q_DECLARE_METATYPE(Tier)
#endif //HCI_PROJECT2020_TIER_H
