#ifndef QTQUICK2_H
#define QTQUICK2_H

#include <QObject>
#include <QList>
#include <QWidget>
#include <QQmlEngine>
#include <QQmlError>

#include "qmlengine.h"

class QmlTools : public QObject 
{
    Q_OBJECT
public:
    QmlTools(QQmlEngine *pEngine);
    
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, PlayerManager* pPlayerManager, Library* pLibrary);
    Q_INVOKABLE void clearComponentCache();
    Q_INVOKABLE void setOutputWarningsToStandardError(bool value);

    Q_INVOKABLE void clearWarnings();
    Q_INVOKABLE QString getLastWarning();
    Q_INVOKABLE QString getWarnings();
    
    Q_INVOKABLE void showControlObjects();

signals:
    void warning();
public slots:
    void setWarnings(QList<QQmlError> warnings);

private:
    QQmlEngine *m_pQQmlEngine;
    QList<QQmlError> m_warnings;

};

#endif // QTQUICK2_H

