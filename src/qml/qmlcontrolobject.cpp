#include "qmlcontrolobject.h"


QmlControlObject::QmlControlObject(QObject *parent)
	: QObject(parent), m_configKey("") {

}

QString QmlControlObject::configKey() const {
	return m_configKey;
}

void QmlControlObject::setConfigKey(QString configKey) {
	m_configKey = configKey;
	ConfigKey key = ConfigKey::parseCommaSeparated(configKey);

	if (m_cot != NULL) {
		delete m_cot;
		m_cot = NULL;
	}

	m_cot = new ControlObjectThread(key);
	if (m_cot == NULL) {
		qWarning() << "QMLMixxxEngine enableEvent: Unknown control" << configKey;
		return;
	}
    
	connect(m_cot, SIGNAL(valueChanged(double)), this, SLOT(updateProperty(double)));
}

void QmlControlObject::setTarget(const QQmlProperty &p) {
	m_targetProperty = p; 
}

void QmlControlObject::updateProperty(double value) {
	m_targetProperty.write(value);
}