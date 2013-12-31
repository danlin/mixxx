#include "qmlerrormodel.h"

QmlErrorModel::QmlErrorModel(QObject *parent)
     : QAbstractListModel(parent)
 {
     QHash<int, QByteArray> roles;
     roles[LineRole] = "line";
     roles[ColumnRole] = "column";
     roles[DescriptionRole] = "description";
     roles[UrlRole] = "url";
     roles[StringRole] = "string";
     setRoleNames(roles);
 }

 void QmlErrorModel::addError(const QQmlError &error) {
     beginInsertRows(QModelIndex(), rowCount(), rowCount());
     m_errors << error;
     endInsertRows();
 }

 int QmlErrorModel::rowCount(const QModelIndex & parent) const {
     return m_errors.count();
 }

 void QmlErrorModel::clear() {
     beginRemoveRows(QModelIndex(), 0, rowCount());
     m_errors.clear();
     endRemoveRows();
 }

 QVariant QmlErrorModel::data(const QModelIndex & index, int role) const {
     if (index.row() < 0 || index.row() > m_errors.count())
         return QVariant();

     const QQmlError &error = m_errors[index.row()];
     if (role == LineRole)
         return error.line();
     else if (role == ColumnRole)
         return error.column();
     else if (role == DescriptionRole)
         return error.description();
     else if (role == UrlRole)
         return error.url();
     else if (role == StringRole)
         return error.toString();

     return QVariant();
 }
