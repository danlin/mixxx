#ifndef QTQUICK2_H
#define QTQUICK2_H

#include <QObject>
#include <QList>
#include <QWidget>
#include <QQmlEngine>
#include <QQmlError>

#include "qmlengine.h"

class QtQuick2 : public QObject 
{
    Q_OBJECT
public:
    QtQuick2(QQmlEngine *engine);
    
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine);
    Q_INVOKABLE void clearComponentCache();
    Q_INVOKABLE void setConsoleWarnings(bool value);
    Q_INVOKABLE void clearWarnings();
    Q_INVOKABLE QString getLastWarning();
    Q_INVOKABLE QString getWarnings();
    
signals:
    void warning();
public slots:
    void setWarnings(QList<QQmlError> warnings);

private:
    QQmlEngine *m_pEngine;
    QList<QQmlError> m_warnings;
};

#endif // QTQUICK2_H

