#include "timeline.h"
#include "ui_timeline.h"
#include "tiermodel.h"

Timeline::Timeline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timeline)
{
    ui->setupUi(this);
    TierModel model;;
    ui->treeView->setModel(&model);
    ui->addTierButton->clicked(updateTreeAction());
}

bool Timeline::updateTreeAction(){
    ui->treeView->model()->insertRows(1,0);
    ui->treeView->update();
    return true;
}

Timeline::~Timeline()
{
    delete ui;
}
