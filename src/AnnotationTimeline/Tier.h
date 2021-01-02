//
// Created by rasmus on 2020-12-29.
//

#ifndef HCI_PROJECT2020_TIER_H
#define HCI_PROJECT2020_TIER_H


#include <string>
#include <list>
#include <QVariant>
#include "Annotation.h"


class Tier {

public:
    explicit Tier(QVariant title, Tier *parentTier = nullptr);
    ~Tier();

    void appendChild(Tier *child);

    Tier *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column);
//    void data(int column, Annotation* returnItem);
    int row();
    Tier *parentTier();

    void setData(int i, const QVariant& variant);

private:

    QVariant title;//Will se if this works, otherwise well have to add it to m_itemData
    
    QVector<Annotation*> m_itemData;

    QVector<Tier*> m_childItems;//Child tiers

    Tier *m_parentTier; //Self explanitory


};


#endif //HCI_PROJECT2020_TIER_H
