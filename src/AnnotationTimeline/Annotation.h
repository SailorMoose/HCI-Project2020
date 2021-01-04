//
// Created by rasmus on 2020-12-29.
//

#ifndef HCI_PROJECT2020_ANNOTATION_H
#define HCI_PROJECT2020_ANNOTATION_H


#include <string>
#include <QVariant>
//#include "Tier.h"
#include <QJsonObject>


class Annotation {
public:

    explicit Annotation(QJsonObject data);
    Annotation();

private:

    QJsonObject m_itemData; //index 0 = startPos, index 1 = endPos, index 2 = text
//    Tier *parent;


};

Q_DECLARE_METATYPE(Annotation*);


#endif //HCI_PROJECT2020_ANNOTATION_H
