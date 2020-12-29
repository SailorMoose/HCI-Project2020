#ifndef TIERLIST_H
#define TIERLIST_H

#include <QAbstractListModel>
#include "Tier.h"

class TierList : public QAbstractListModel
{
    Q_OBJECT
private:
    Tier *tierList;
    int rows;

public:
    explicit TierList(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // TIERLIST_H
