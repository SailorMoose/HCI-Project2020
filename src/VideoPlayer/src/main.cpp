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

#include <QApplication>
#include <QQmlContext>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Creating the view and manually setting the QML file it should display
    QQuickView view;
    view.setSource(QStringLiteral("qrc:/VideoPlayer.qml"));

    // Retrieving the QML context. This context allows us to expose data to the QML components
    QQmlContext* rootContext = view.rootContext();

    // Creating 2 new properties: the width and height of the view
    rootContext->setContextProperty("WINDOW_WIDTH", 640);
    rootContext->setContextProperty("WINDOW_HEIGHT", 360);

    // Let's display the view
    view.show();

    return app.exec();
}
