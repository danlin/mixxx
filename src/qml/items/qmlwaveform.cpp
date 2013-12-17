#include <QPainter>

#include "qmlwaveform.h"

QmlWaveform::QmlWaveform() {
    m_waveformWidgetRenderer = new WaveformWidgetRenderer("[Channel1]");
    m_renderer = new GLWaveformRendererFilteredSignal(m_waveformWidgetRenderer);
    connect(this, SIGNAL(windowChanged(QQuickWindow*)), this, SLOT(handleWindowChanged(QQuickWindow*)));
}

void QmlWaveform::handleWindowChanged(QQuickWindow *win) {
    if (win) {
        // Connect the beforeRendering signal to our paint function.
        // Since this call is executed on the rendering thread it must be
        // a Qt::DirectConnection
        connect(win, SIGNAL(beforeRendering()), this, SLOT(paint()), Qt::DirectConnection);
        connect(win, SIGNAL(beforeSynchronizing()), this, SLOT(sync()), Qt::DirectConnection);
        
        // If we allow QML to do the clearing, they would clear what we paint
        // and nothing would show.
        win->setClearBeforeRendering(false);
    }
}

void QmlWaveform::cleanup() {
    if (m_waveformWidgetRenderer) {
        delete m_waveformWidgetRenderer;
        m_waveformWidgetRenderer = 0;
    }
}

void QmlWaveform::paint() {
    QPainter painter;
    m_renderer->draw(&painter, NULL);
}

void QmlWaveform::sync() {

}