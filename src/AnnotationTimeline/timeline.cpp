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
//    AnnotationModel* aModel = new AnnotationModel();
    ui->tableView->setModel(&aModel);
    connect(ui->addTierButton, &QPushButton::clicked, this,&Timeline::on_addTier_pressed);
    connect(ui->removeTierButton, &QPushButton::clicked, this, &Timeline::on_removeTier_clicked);
    connect(ui->addAnnotationsButton,&QPushButton::clicked, this, &Timeline::on_addAnnotation_clicked);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::currentChanged, this, &Timeline::on_TierChanged);


}

bool Timeline::on_addTier_pressed(){
    QString title = QInputDialog::getText(this,tr("Add Tier"),tr("Tier Name"),QLineEdit::Normal);
    if(title.isEmpty()){
        return false;
    }
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

bool Timeline::on_addAnnotation_clicked(){
    QString text = QInputDialog::getText(this,tr("Add Annotation"),tr("Annotation text"),QLineEdit::Normal);
    if(text.isEmpty()){
        return false;
    }
    aModel.addAnnotation(2,3,text);
    return true;
}

bool Timeline::on_TierChanged(){
    QModelIndex selected = ui->treeView->selectionModel()->currentIndex();
    aModel.setRoot(selected);
    return true;
}



Timeline::~Timeline()
{
    delete ui;
}
