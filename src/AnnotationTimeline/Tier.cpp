//
// Created by rasmus on 2020-12-29.
//

#include "Tier.h"


Tier::Tier(QString title, Tier* parentTier){
    this->_title=std::move(title);
    this->_parent=parentTier;
}

Tier::~Tier(){
    qDeleteAll(this->_childTiers);
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
