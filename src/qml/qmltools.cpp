#include <QDebug>
#include <QMessageBox>

#include <QQuickView>
#include <QQmlError>
#include <QQmlContext>

#include "qmltools.h"

QmlTools::QmlTools(QQmlEngine *pEngine)
    : m_pEngine(pEngine) {
        connect(pEngine, SIGNAL(warnings(QList<QQmlError>)), this, SLOT(setWarnings(QList<QQmlError>)));
}

void QmlTools::clearComponentCache() {
    m_pEngine->clearComponentCache();
}

void QmlTools::setConsoleWarnings(bool value) {
    m_pEngine->setOutputWarningsToStandardError(value);
}

void QmlTools::setWarnings(QList<QQmlError> warnings) {
    m_warnings.append(warnings);
    emit(warning());
}

void QmlTools::clearWarnings() {
    m_warnings.clear();
}

QString QmlTools::getLastWarning() {
    if (m_warnings.empty()) {
        return "";
    }
    
    return m_warnings.at(m_warnings.length() - 1).toString();
}

QString QmlTools::getWarnings() {
    if (m_warnings.empty()) {
        return "";
    }
    
    QString warnings;
    for (int i = 0; i < m_warnings.length(); ++i) {
        warnings += m_warnings.at(i).toString() + "\n";
    }
    
    return warnings;
}


void QmlTools::setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine) {
	QQuickView *pQQuickView = new QQuickView;
	pQQuickView->setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *pContext = pQQuickView->rootContext();
    QQmlEngine *pEngine = pContext->engine();
    QmlTools *pMixxxTools = new QmlTools(pEngine);
    
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
