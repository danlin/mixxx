#ifndef QMLWAVEFORM_H
#define QMLWAVEFORM_H

#include <QObject>
#include <QQuickItem>
#include <QQuickWindow>

#include "waveform/renderers/waveformwidgetrenderer.h"
#include "waveform/renderers/glwaveformrenderersimplesignal.h"

class QmlWaveform : public QQuickItem
{
    Q_OBJECT
    
public:
	QmlWaveform();
public slots:
    void paint();
    void cleanup();
    void sync();
    
private slots:
    void handleWindowChanged(QQuickWindow *win);
    
private:
    WaveformWidgetRenderer* m_waveformWidgetRenderer;
    GLWaveformRendererSimpleSignal *m_renderer;
};

#endif // QMLWAVEFORM_H

