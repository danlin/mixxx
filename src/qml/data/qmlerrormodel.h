#ifndef QMLERRORMODEL_H
#define QMLERRORMODEL_H

#include <QAbstractListModel>
#include <QQmlError>

class QmlErrorModel : public QAbstractListModel
{
    Q_OBJECT
public:
    QmlErrorModel(QObject *parent = 0);

    enum ErrorRoles {
        LineRole = Qt::UserRole + 1,
        ColumnRole,
        DescriptionRole,
        UrlRole,
        StringRole
    };

    void addError(const QQmlError &error);
    void clear();
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
private:
     QList<QQmlError> m_errors;

};

#endif // QMLERRORMODEL_H
