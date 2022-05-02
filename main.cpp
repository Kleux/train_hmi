#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQuickItem>
#include "konnect.h"
#include<QQmlContext>
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//qmlRegisterType<konnect>("com.Konnect", 1, 0, "Konnect");
    QGuiApplication app(argc, argv);
    konnect testClass;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("klass",&testClass);
    return app.exec();
}
