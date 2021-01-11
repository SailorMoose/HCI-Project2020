#ifndef TIMELINE_H
#define TIMELINE_H

#include "annotationmodel.h"

#include <QWidget>
#include <tiermodel.h>

namespace Ui {
class Timeline;
}

class Timeline : public QWidget
{
    Q_OBJECT

public:
    explicit Timeline(QWidget *parent = nullptr);
    ~Timeline();

public slots:
    bool on_addTier_pressed();
    bool on_removeTier_clicked();
    bool on_addAnnotation_clicked();
    bool on_TierChanged();

private:
    Ui::Timeline *ui;
    TierModel model;
    AnnotationModel aModel;
};

#endif // TIMELINE_H
