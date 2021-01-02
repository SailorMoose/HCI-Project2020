//
// Created by rasmus on 2020-12-29.
//

#include "Tier.h"

#include <utility>

Tier::Tier(QVariant title, Tier *parentTier): title(std::move(title)), m_parentTier(parentTier) {

}

Tier::~Tier() {
    qDeleteAll(m_childItems);
    qDeleteAll(m_itemData);
}

void Tier::appendChild(Tier *child) {
    m_childItems.append(child);
}

Tier *Tier::child(int row) {
    if(row < 0 || row >= m_childItems.size()) {
        return nullptr;
    }
    return m_childItems.at(row);
}

int Tier::childCount() const {
    return m_childItems.count();
}

int Tier::columnCount() const {
    return m_itemData.size() + 1;
}

Tier *Tier::parentTier() {
    return m_parentTier;
}

int Tier::row() {
    if(m_parentTier){
        return m_parentTier->m_childItems.indexOf(const_cast<Tier*>(this));
    }
    return 0;
}

QVariant Tier::data(int column) {
    if(column==0){
        return title;
    }
    return QVariant::fromValue(m_itemData.at(column-1));
}

void Tier::setData(int i, const QVariant& variant) {
    m_itemData.removeAt(i);
    m_itemData.insert(i,new Annotation(variant.toJsonObject()));
}
