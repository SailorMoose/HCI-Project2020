#include "timeline.h"
#include "ui_timeline.h"

#include <QInputDialog>

Timeline::Timeline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timeline)
{
//    model=new TierModel();
    ui->setupUi(this);
    ui->treeView->setModel(&model);
    connect(ui->addTierButton, &QPushButton::clicked, this,&Timeline::on_addTier_pressed);
}

bool Timeline::on_addTier_pressed(){
    QString title = QInputDialog::getText(this,tr("Add Tier"),tr("Tier Name"),QLineEdit::Normal);
    QModelIndex selected = ui->treeView->currentIndex();
    if(selected.isValid()){
        model.addTier(selected,title);
    }else{
        model.addTier(selected,title);
    }
//    ui->treeView->update();
    return true;
}

Timeline::~Timeline()
{
    delete ui;
}
