#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>

namespace Ui {
class Timeline;
}

class Timeline : public QWidget
{
    Q_OBJECT

public:
    explicit Timeline(QWidget *parent = nullptr);
    ~Timeline();

private:
    Ui::Timeline *ui;
};

#endif // TIMELINE_H
