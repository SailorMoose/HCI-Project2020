#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <src/AnnotationTimeline/timeline.h>

#include <src/VideoPlayer/videodockwidget.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Timeline *timeline = new Timeline();
    ui->setupUi(this);
    addDockWidget(Qt::BottomDockWidgetArea,timeline);
    VideoDockWidget *video = new VideoDockWidget();
    addDockWidget(Qt::TopDockWidgetArea,video);


}

MainWindow::~MainWindow()
{
    delete ui;
}
