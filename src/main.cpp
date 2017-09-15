#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>


#include "TableModel.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<TableModel>("Models", 1, 0, "TModel");

    auto* m = new TableModel;
    qDebug() << m->_h();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
