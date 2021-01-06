#ifndef TIMELINE_H
#define TIMELINE_H

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

private:
    Ui::Timeline *ui;
    TierModel model;
};

#endif // TIMELINE_H
