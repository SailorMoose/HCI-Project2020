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

    Annotation() = default;
    ~Annotation() = default;
    Annotation(const Annotation &) = default;
    Annotation &operator=(const Annotation &) = default;

    Annotation(qlonglong startpos, qlonglong endpos, const QString &text);

private:

    qlonglong _startpos;
    qlonglong _endpos;
    QString _text;


};

Q_DECLARE_METATYPE(Annotation*);


#endif //HCI_PROJECT2020_ANNOTATION_H
