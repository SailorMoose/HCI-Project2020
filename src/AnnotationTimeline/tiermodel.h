#ifndef TIERMODEL_H
#define TIERMODEL_H

#include <QAbstractItemModel>
#include <QDialog>
#include "Tier.h"

class TierModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    //Constructor and deconstructor
    explicit TierModel(QObject *parent = nullptr);
    ~TierModel() override;

    //Return index for the view
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    //Return the index of parent
    QModelIndex parent(const QModelIndex &child) const override;

    //add and remove Tiers
    bool addTier(const QModelIndex &parent, QString title);
    bool removeTier(int row, const QModelIndex &parent);

    //Basic grabbing of data, should be changed to return both title and annotations
    QVariant data(const QModelIndex &index, int role) const override;

   //Amount of rows and amount of columns(data) of a tier
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    //Get Header
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;



private:
    Tier *root;

    QVector<Annotation *> getAnnotations(const QModelIndex &parent);
};

#endif // TIERMODEL_H
