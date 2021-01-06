#ifndef VIDEODOCKWIDGET_H
#define VIDEODOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
class VideoDockWidget;
}

class VideoDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit VideoDockWidget(QWidget *parent = nullptr);
    ~VideoDockWidget();

private:
    Ui::VideoDockWidget *ui;
};

#endif // VIDEODOCKWIDGET_H
