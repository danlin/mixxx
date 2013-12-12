#ifndef QTQUICK2_H
#define QTQUICK2_H

#include <QObject>
#include <QWidget>

#include "qmlengine.h"

class QtQuick2 : public QObject 
{
    Q_OBJECT
public:
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, QmlEngine *pQmlEngine);
};

#endif // QTQUICK2_H

