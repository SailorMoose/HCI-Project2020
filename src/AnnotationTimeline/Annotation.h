//
// Created by rasmus on 2020-12-29.
//

#ifndef HCI_PROJECT2020_ANNOTATION_H
#define HCI_PROJECT2020_ANNOTATION_H


#include <string>

class Annotation {

private:
    
    QVector<QVariant> m_itemData; //index 0 = startPos, index 1 = endPos, index 2 = text
    Tier *parent;


};


#endif //HCI_PROJECT2020_ANNOTATION_H
