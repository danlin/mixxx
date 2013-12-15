#include <QDebug>
#include <QMessageBox>

#include <QQuickView>
#include <QQmlError>
#include <QQmlContext>

#include "qtquick2.h"

QtQuick2::QtQuick2(QQmlEngine *pEngine)
    : m_pEngine(pEngine) {
        connect(pEngine, SIGNAL(warnings(QList<QQmlError>)), this, SLOT(setWarnings(QList<QQmlError>)));
}

void QtQuick2::clearComponentCache() {
    m_pEngine->clearComponentCache();
}

void QtQuick2::setConsoleWarnings(bool value) {
    m_pEngine->setOutputWarningsToStandardError(value);
}

void QtQuick2::setWarnings(QList<QQmlError> warnings) {
    m_warnings.append(warnings);
    emit(warning());
}

void QtQuick2::clearWarnings() {
    m_warnings.clear();
}

QString QtQuick2::getLastWarning() {
    if (m_warnings.empty()) {
        return "";
    }
    
    return m_warnings.at(m_warnings.length() - 1).toString();
}

QString QtQuick2::getWarnings() {
    if (m_warnings.empty()) {
        return "";
    }
    
    QString warnings;
    for (int i = 0; i < m_warnings.length(); ++i) {
        warnings += m_warnings.at(i).toString() + "\n";
    }
    
    return warnings;
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
