#include <QCoreApplication>
#include <QtQml>
#include "CppNode.h"

int main(int argc,char **argv)
{
    QCoreApplication app(argc,argv);
    qmlRegisterType<CppNode>("App", 1, 0, "CppNode");

    QQmlEngine engine;
    engine.addImportPath("/home/yruan/QFlow-master");
    engine.addPluginPath("/home/yruan/QFlow-master");
    QQmlComponent rootComponent(&engine);
    rootComponent.loadUrl(QUrl("./qml/Main.qml"));
    if(rootComponent.status() != QQmlComponent::Ready)
    {
        qDebug() << "Not Ready!!!"  << rootComponent.errorString();
        return -1;
    }
    rootComponent.create();
    if(rootComponent.isError()){
        qDebug() << rootComponent.errorString();
        return -1;
    }

    return app.exec();
}

