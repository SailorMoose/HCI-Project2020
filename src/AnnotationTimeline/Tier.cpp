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

#include "Tier.h"


Tier::Tier(QString title, Tier* parentTier){
    this->_title=std::move(title);
    this->_parent=parentTier;
}

Tier::~Tier(){
    qDeleteAll(this->_childTiers);
    qDeleteAll(this->annotations);
}

Tier* Tier::getParent(){
        return _parent;
}

int Tier::parentPos(){
    if(_parent){
        return _parent->_childTiers.indexOf(const_cast<Tier*>(this));
    }
    return 0;
}

int Tier::childCount(){
    return _childTiers.count();
}

Tier* Tier::getChildAt(int pos){
    return _childTiers.at(pos);
}

void Tier::appendChild(Tier* child){
    _childTiers.append(child);
}

void Tier::insertChild(Tier *child, int pos){
     _childTiers.insert(pos, child);
}

bool Tier::removeChild(Tier *child){
    return _childTiers.removeOne(child);
}

void Tier::removeChildAt(int pos){
    _childTiers.removeAt(pos);
}

void Tier::setTitle(QString title){
    this->_title=std::move(title);
}

QString Tier::getTitle(){
    return this->_title;
}

QVector<Annotation*> Tier::getData() {
    return annotations;
}

void Tier::addAnnotation(qlonglong start, qlonglong end, QString text)
{
    annotations.append(new Annotation(start, end, text));
}
