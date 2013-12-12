#include <QGLWidget>
#include <QDebug>
#include <QMessageBox>

#include <QDeclarativeView>
#include <QDeclarativeError>
#include <QDeclarativeContext>

#include "qtquick1.h"

void QtQuick1::setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine) {
	QDeclarativeView *pQmlView = new QDeclarativeView;
    QDeclarativeContext *pContext = pQmlView->rootContext();
    pContext->setContextProperty("MixxxEngine", pQmlEngine);
    
    // Set optimizations not already done in QDeclarativeView
    pQmlView->setAttribute(Qt::WA_OpaquePaintEvent);
    pQmlView->setAttribute(Qt::WA_NoSystemBackground);
    // Make QDeclarativeView use OpenGL backend
    QGLWidget *glWidget = new QGLWidget(QGLFormat(QGL::SampleBuffers));
    pQmlView->setViewport(glWidget);
    pQmlView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    qDebug() << "Load QTQuick 1 File:" << skinQmlPath;
    pQmlView->setSource(QUrl::fromLocalFile(skinQmlPath));
    if (!pQmlView->errors().empty()) {
        for (int i = 0; i < pQmlView->errors().length(); ++i) {
            QMessageBox msgBox(QMessageBox::Critical, pQmlView->errors().at(i).description(), pQmlView->errors().at(i).toString());
            msgBox.exec();
        }
        exit(1);
    }
    
    pQmlView->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    QVBoxLayout *pLayout = new QVBoxLayout(pQmlWidget);
    pLayout->addWidget(pQmlView);
    pLayout->setContentsMargins(0, 0, 0, 0);
}