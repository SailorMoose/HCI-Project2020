#include "timeline.h"
#include "ui_timeline.h"

#include <QInputDialog>
#include <QMessageBox>

Timeline::Timeline(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Timeline)
{
    ui->setupUi(this);
    ui->treeView->setModel(&model);
    connect(ui->addTierButton, &QPushButton::clicked, this,&Timeline::on_addTier_pressed);
    connect(ui->removeTierButton, &QPushButton::clicked, this, &Timeline::on_removeTier_clicked);
}

bool Timeline::on_addTier_pressed(){
    QString title = QInputDialog::getText(this,tr("Add Tier"),tr("Tier Name"),QLineEdit::Normal);
    QModelIndex selected = ui->treeView->currentIndex();
    if(selected.isValid()){
        model.addTier(selected,title);
    }else{
        model.addTier(selected,title);
    }
    return true;
}


bool Timeline::on_removeTier_clicked(){
    QMessageBox notification;
    QModelIndex selected = ui->treeView->currentIndex();
    if(selected.isValid()){
        model.removeTier(selected.row(),selected.parent());
        notification.setText("Tier removed");
    }else{
        notification.setText("No Tier selected");
    }
    notification.exec();
    return true;
}

Timeline::~Timeline()
{
    delete ui;
}
