#ifndef QMLCONTROLOBJECT_H
#define QMLCONTROLOBJECT_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlPropertyValueSource>
#include <QQmlProperty>
#include <QQml.h>
#include <QtCore/qfactoryinterface.h>

#include "configobject.h"
#include "controlobject.h"
#include "controlobjectthread.h"

class QmlControlObject : public QObject, public QQmlPropertyValueSource
{
    Q_OBJECT
    Q_INTERFACES(QQmlPropertyValueSource)
    Q_PROPERTY(string configKey READ configKey WRITE setConfigKey NOTIFY configKeyChanged);
public:
    QmlControlObject(QObject *parent = 0);

    QString configKey() const;
    void setConfigKey(QString configKey);

    virtual void setTarget(const QQmlProperty &);

signals:
    void configKeyChanged();

private slots:
    void updateProperty(double value);

private:
    QQmlProperty m_targetProperty;
    ControlObjectThread *m_cot;
    QString m_configKey;
};

#endif // QMLCONTROLOBJECT_H