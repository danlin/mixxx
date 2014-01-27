#ifndef QMLOVERVIEW_H
#define QMLOVERVIEW_H

#include <QtQuick>

#include "../../widget/woverview.h"

class QmlOverview : public QQuickPaintedItem
{
    Q_OBJECT

    public:
        QmlOverview(QQuickItem *parent = 0);
        void paint(QPainter *painter);

    private:
        WOverview *m_pWOverview;
    signals:
};


#endif // QMLOVERVIEW_H

