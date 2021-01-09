//
// Created by rasmus on 2020-12-29.
//

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
    QVector<QJsonObject> getData();



private:

    Tier* _parent;
    QString _title;
    QVector<Tier*> _childTiers;
    QVector<Annotation*> annotations;

};

//Q_DECLARE_METATYPE(Tier)
#endif //HCI_PROJECT2020_TIER_H
