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

    bool on_addTier_pressed();
private:
    Ui::Timeline *ui;
    TierModel model;
};

#endif // TIMELINE_H
