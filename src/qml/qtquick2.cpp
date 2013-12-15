#include <QDebug>
#include <QMessageBox>

#include <QQuickView>
#include <QQmlError>
#include <QQmlContext>

#include "qtquick2.h"

QtQuick2::QtQuick2(QQmlEngine *pEngine)
    : m_pEngine(pEngine) {
    
}

void QtQuick2::clearComponentCache() {
    m_pEngine->clearComponentCache();
}

void QtQuick2::setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine) {
	QQuickView *pQQuickView = new QQuickView;
	pQQuickView->setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *pContext = pQQuickView->rootContext();
    QQmlEngine *pEngine = pContext->engine();
    QtQuick2 *pMixxxTools = new QtQuick2(pEngine);
    
    pContext->setContextProperty("MixxxEngine", pQmlEngine);
    pContext->setContextProperty("MixxxTools", pMixxxTools);

    qDebug() << "Load QTQuick 2 File:" << skinQmlPath;
    pQQuickView->setSource(QUrl::fromLocalFile(skinQmlPath));
    if (!pQQuickView->errors().empty()) {
        for (int i = 0; i < pQQuickView->errors().length(); ++i) {
            QMessageBox msgBox(QMessageBox::Critical, pQQuickView->errors().at(i).description(), pQQuickView->errors().at(i).toString());
            msgBox.exec();
        }
        exit(1);
    }
    
    QWidget *container = QWidget::createWindowContainer(pQQuickView);
    QVBoxLayout *pLayout = new QVBoxLayout(pQmlWidget);
    pLayout->addWidget(container);
    pLayout->setContentsMargins(0, 0, 0, 0);
}
