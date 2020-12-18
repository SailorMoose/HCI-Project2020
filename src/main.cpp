#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QWidget>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QApplication app(argc, argv);
//    QQuickStyle::setStyle("Material");
    app.setApplicationDisplayName("Elanlike");
    app.setOrganizationName("Grupp 5");
    app.setOrganizationDomain("ORU");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/src/prototype_rasmus_qtquick.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
