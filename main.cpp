#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "BlockGenerator.hpp"
#include "Blocks.hpp"
#include "Tester.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    Blocks* blocks = new Blocks();

    Tester *tester = new Tester();
    Q_UNUSED(tester);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("screenWidth", SCREEN_WIDTH);
    engine.rootContext()->setContextProperty("screenHeight", SCREEN_HEIGHT);
    engine.rootContext()->setContextProperty("blocks", blocks);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
