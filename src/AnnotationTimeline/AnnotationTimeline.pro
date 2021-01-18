#/*
# * Copyright 2021 - Rasmus Olstedt, Kjell Engehjelm, Daniel Malm
# *
# * This file is part of HCI-Project2020
# *
# * HCI-Project2020 is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 3 of the License, or
# * (at your option) any later version.
# *
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with this program.  If not, see <https://www.gnu.org/licenses/>.
# * */

#QT += quick \
#    widgets \
#    core \
#    gui

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        annotationmodel.cpp \
        main.cpp \
        tiermodel.cpp \
        timeline.cpp \
        Tier.cpp \
        Annotation.cpp

RESOURCES += qml.qrc

FORMS += \
    timeline.ui

HEADERS += \
    annotationmodel.h \
    tiermodel.h \
    timeline.h \
    Tier.h \
    Annotation.h

TRANSLATIONS += \
    AnnotationTimeline_en_SE.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


