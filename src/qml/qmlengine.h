#ifndef QMLENGINE_H
#define QMLENGINE_H

#include "playermanager.h"
#include "basetrackplayer.h"
#include "library/library.h"

class ControlObjectThread;

class QmlEngine : public QObject
{
    Q_OBJECT
public:
    // Engine Values read write
    Q_INVOKABLE double getValue(QString configKey);
    Q_INVOKABLE void setValue(QString configKey, double newValue);
    // Track Properties
    Q_INVOKABLE QString getTrackProperty(QString group, QString property);
    // Engine Events
    Q_INVOKABLE void enableEvent(QString configKey);
    Q_INVOKABLE void disableEvent(QString configKey);
    // Player Events
    Q_INVOKABLE void enablePlayerEvents(QString group);
    Q_INVOKABLE void disablePlayerEvents(QString group);

    explicit QmlEngine();
    // Setup the MixxxEngine Item
    void setup(PlayerManager* pPlayerManager, Library* pLibrary);
    void initialized();
signals:
    void valueChanged(QString eventKey, double value);
    void isInitialized();
    
    public slots:
    // Engine Slots
    void slotValueChanged(double value);
    // Track Slots
    void slotLoadTrack(TrackPointer);
    void slotNewTrackLoaded(TrackPointer);
    void slotUnloadingTrack(TrackPointer);
    
private:
    ControlObjectThread* getControlObjectThread(ConfigKey key);
    QHash<ConfigKey, ControlObjectThread*> m_controlCache;
    PlayerManager* m_pPlayerManager;
    Library* m_pLibrary;
};

#endif // QMLENGINE_H

