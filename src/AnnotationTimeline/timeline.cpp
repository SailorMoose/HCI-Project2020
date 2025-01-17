/*
 * Copyright 2021 - Rasmus Olstedt, Kjell Engehjelm, Daniel Malm
 *
 * This file is part of HCI-Project2020
 *
 * HCI-Project2020 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * */

#include "timeline.h"
#include "ui_timeline.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QEvent>

Timeline::Timeline(QDockWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Timeline)
{
    ui->setupUi(this);
    ui->treeView->setModel(&model);
    ui->tableView->setModel(&aModel);
    ui->treeView->viewport()->installEventFilter(this);
    connect(ui->addTierButton, &QPushButton::clicked, this,&Timeline::on_addTier_pressed);
    connect(ui->removeTierButton, &QPushButton::clicked, this, &Timeline::on_removeTier_clicked);
    connect(ui->addAnnotationsButton,&QPushButton::clicked, this, &Timeline::on_addAnnotation_clicked);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::currentChanged, this, &Timeline::on_TierChanged);
}



bool Timeline::eventFilter(QObject *watched, QEvent *event){
    if (event->type() == QEvent::MouseButtonPress){
        if(!ui->treeView->indexAt(ui->treeView->cursor().pos()).isValid() && ui->treeView->currentIndex().isValid()){
            ui->treeView->selectionModel()->clear();
            return true;
        }
        else return false;

    }
    return false;
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

bool Timeline::on_treeViewPortClicked()
{
    return false;
}

Timeline::~Timeline()
{
    delete ui;
}
