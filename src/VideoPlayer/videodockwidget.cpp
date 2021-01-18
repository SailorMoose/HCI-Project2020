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
