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

    std::string title;

    std::list<Annotation> annotations;

    Tier *subTiers;


};


#endif //HCI_PROJECT2020_TIER_H
