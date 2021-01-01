//
// Created by rasmus on 2020-12-29.
//

#ifndef HCI_PROJECT2020_TIER_H
#define HCI_PROJECT2020_TIER_H


#include <string>
#include <list>
#include "Annotation.h"

class Tier {

private:

    QVariant title;//Will se if this works, otherwise well have to add it to m_itemData
    
    QVector<Annotation*> m_itemData

    QVector<Tiers*> m_childItems;//Child tiers

    Tier *parentTier; //Self explanitory


};


#endif //HCI_PROJECT2020_TIER_H
