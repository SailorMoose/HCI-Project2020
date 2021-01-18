#ifndef TIMELINE_H
#define TIMELINE_H

#include "annotationmodel.h"

#include <QDockWidget>
#include <QWidget>
#include "tiermodel.h"

namespace Ui {
class Timeline;
}

class Timeline : public QDockWidget
{
    Q_OBJECT

public:
    explicit Timeline(QDockWidget *parent = nullptr);
    ~Timeline();
    bool eventFilter(QObject *watched, QEvent *event) override;

public slots:
    bool on_addTier_pressed();
    bool on_removeTier_clicked();
    bool on_addAnnotation_clicked();
    bool on_TierChanged();
    bool on_treeViewPortClicked();

private:
    Ui::Timeline *ui;
    TierModel model;
    AnnotationModel aModel;
};

#endif // TIMELINE_H
