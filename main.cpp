#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "BlockGenerator.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    BlockGenerator* blocks = BlockGenerator::getInstance();
    blocks->doSomething();

    QQmlApplicationEngine* engine = new QQmlApplicationEngine();

    engine->rootContext()->setContextProperty("screenWidth", SCREEN_WIDTH);
    engine->rootContext()->setContextProperty("screenHeight", SCREEN_HEIGHT);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine->load(url);

    return app.exec();
}
