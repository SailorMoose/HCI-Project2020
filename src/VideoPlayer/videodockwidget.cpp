#include "videodockwidget.h"
#include "ui_videodockwidget.h"

VideoDockWidget::VideoDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::VideoDockWidget)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl("qrc:/src/VideoPlayer/VideoPlayer.qml"));
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

VideoDockWidget::~VideoDockWidget()
{
    delete ui;
}
