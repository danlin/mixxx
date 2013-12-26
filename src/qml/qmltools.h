#ifndef QTQUICK2_H
#define QTQUICK2_H

#include <QObject>
#include <QList>
#include <QWidget>
#include <QQmlEngine>
#include <QQmlError>

#include "qmlengine.h"

class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    
public:
    DataObject(QObject *parent, QString name, QString color) :
        QObject(parent),
        m_name(name),
        m_color(color) {

        }

    QString name() {
        return m_name;
    }
    QString color() {
        return m_color;
    }
    void setName(QString name) {
        m_name = name;
    }
    void setColor(QString color) {
        m_color = color;
    }
signals:
    QString nameChanged();
    QString colorChanged();
private:
    QString m_name;
    QString m_color;
};


class QmlTools : public QObject 
{
    Q_OBJECT
public:
    QmlTools(QQmlEngine *pEngine);
    
	static void setupWidget(QWidget* pQmlWidget, QString skinQmlPath, PlayerManager* pPlayerManager, Library* pLibrary);
    Q_INVOKABLE void clearComponentCache();
    Q_INVOKABLE void setOutputWarningsToStandardError(bool value);

    Q_INVOKABLE void clearWarnings();
    
    Q_INVOKABLE void showControlObjects();

signals:
    void warning();
public slots:
    void setWarnings(QList<QQmlError> warnings);

private:
    QQmlEngine *m_pQQmlEngine;
    QList<QObject*> m_warnings;
};

#endif // QTQUICK2_H

