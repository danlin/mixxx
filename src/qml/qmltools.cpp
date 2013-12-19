#include <QDebug>
#include <QMessageBox>

#include <QQuickView>
#include <QQmlError>
#include <QQmlContext>

#include "qmltools.h"
#include "qmlengine.h"

QmlTools::QmlTools(QQmlEngine *pQQmlEngine)
    : m_pQQmlEngine(pQQmlEngine) {
    
    connect(m_pQQmlEngine, SIGNAL(warnings(QList<QQmlError>)), this, SLOT(setWarnings(QList<QQmlError>)));
    QQmlContext *pContext = pQQmlEngine->rootContext();

    /*
    QList<QObject*> dataList;
    for (int i = 0; i <10000; i ++) {
        CppType *type = new CppType();
        type->root = i;
        dataList.append(type);
    }
    pContext->setContextProperty("MixxxWarnings", QVariant::fromValue(dataList));
    */
}

void QmlTools::clearComponentCache() {
    m_pQQmlEngine->clearComponentCache();
}

void QmlTools::setOutputWarningsToStandardError(bool value) {
    m_pQQmlEngine->setOutputWarningsToStandardError(value);
}

void QmlTools::setWarnings(QList<QQmlError> warnings) {
    for (int index = 0; index < warnings.length(); index++) {
        m_warnings.append(warnings.at(index));
    }
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

void QmlTools::showControlObjects() {
    QList<QObject*> dataList;

    // Check for leaked ControlObjects and give warnings.
    QList<ControlDoublePrivate*> leakedControls;
    QList<ConfigKey> leakedConfigKeys;

    ControlDoublePrivate::getControls(&leakedControls);

    if (leakedControls.size() > 0) {
        foreach (ControlDoublePrivate* pCOP, leakedControls) {
            ConfigKey key = pCOP->getKey();
            leakedConfigKeys.append(key);
        }

       foreach (ConfigKey key, leakedConfigKeys) {
           // delete just to satisfy valgrind:
           // check if the pointer is still valid, the control object may have bin already
           // deleted by its parent in this loop
           ControlObject* pCo = ControlObject::getControl(key, false);
           if (pCo) {

           }
       }
   }
}

void QmlTools::setupWidget(QWidget* pQmlWidget, QString skinQmlPath, PlayerManager* pPlayerManager, Library* pLibrary) {
    QmlEngine *pQmlEngine = new QmlEngine();
    pQmlEngine->setup(pPlayerManager, pLibrary);
	QQuickView *pQQuickView = new QQuickView;
	pQQuickView->setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *pContext = pQQuickView->rootContext();
    QQmlEngine *pEngine = pContext->engine();
    QmlTools *pMixxxTools = new QmlTools(pEngine);
    
    QList<QObject*> m_pDataList;

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
    pQmlEngine->initialized();
}
