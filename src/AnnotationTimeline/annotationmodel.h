#ifndef ANNOTATIONMODEL_H
#define ANNOTATIONMODEL_H

#include <iostream>
#include <QAbstractItemModel>
#include "Annotation.h"
#include "Tier.h"

class AnnotationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AnnotationModel(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setRoot(QModelIndex &parent);

     void addAnnotation(qlonglong start, qlonglong end, const QString& text);

     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QModelIndex *_rootIndex_;
    Tier* root;


};

#endif // ANNOTATIONMODEL_H
