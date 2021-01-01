#include "timeline.h"
#include "ui_timeline.h"

Timeline::Timeline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timeline)
{
    ui->setupUi(this);
}

Timeline::~Timeline()
{
    delete ui;
}
