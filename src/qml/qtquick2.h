#ifndef QTQUICK2_H
#define QTQUICK2_H

#include <QObject>
#include <QWidget>
#include <QQmlEngine>

#include "qmlengine.h"

class QtQuick2 : public QObject 
{
    Q_OBJECT
public:
    QtQuick2(QQmlEngine *engine);
    
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine);
    Q_INVOKABLE void clearComponentCache();
private:
    QQmlEngine *m_pEngine;
};

#endif // QTQUICK2_H

