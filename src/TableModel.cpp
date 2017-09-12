#include "TableModel.h"

TableModel::TableModel(QObject* parent) :
    QAbstractListModel(parent), m_width(10), m_height(10) {}

TableModel::TableModel(int width, int height) :
    QAbstractListModel(), m_width(width), m_height(height) {}


int TableModel::rowCount(const QModelIndex&) const
{
    return m_width * m_height;
}


QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()) { return QVariant(); }

    switch (role) {
    case Roles::ColorRole:
        return QVariant(QColor(255, 0, 0));
    default:
        return QVariant();
    }
}


QHash<int, QByteArray> TableModel::roleNames() const { return roles; }
