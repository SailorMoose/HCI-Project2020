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
