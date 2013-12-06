#include <QtGui/QGuiApplication>
#include <QDebug>
#include "qtquick2applicationviewer.h"
#include "qqmlcontext.h"

#include "commhandler.h"
#include "colormodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

	CommHandler comm;
	ColorModel model;

    QtQuick2ApplicationViewer viewer;
	viewer.rootContext()->setContextProperty("comm", &comm);
	viewer.rootContext()->setContextProperty("model", &model);
    viewer.setMainQmlFile(QStringLiteral("qml/QtLight/main.qml"));
    viewer.showExpanded();

#ifdef Q_OS_UNIX
	qDebug() << "You are on Unix";
#endif
#ifdef Q_OS_WIN
	qDebug() << "You are on Windows";
#endif

    return app.exec();
}
