#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "multiuavsimqmlglobal.h"

static QObject* multiUAVSimQmlGlobalSingletonFactory(QQmlEngine*, QJSEngine*);

int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationName("MultiUAVSim");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<MultiUAVSimQmlGlobal>("MultiUAVSim", 1, 0, "MultiUAVSim", multiUAVSimQmlGlobalSingletonFactory);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));


    return app.exec();
}

static QObject* multiUAVSimQmlGlobalSingletonFactory(QQmlEngine*, QJSEngine*)
{
    MultiUAVSimQmlGlobal* qmlGlobal = new MultiUAVSimQmlGlobal();
    return qmlGlobal;
}


