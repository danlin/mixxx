#ifndef QTQUICK1_H
#define QTQUICK1_H

#include <QObject>
#include <QWidget>

#include "qmlengine.h"

class QtQuick1 : public QObject
{
    Q_OBJECT
public:
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine);
};

#endif // QTQUICK1_H

