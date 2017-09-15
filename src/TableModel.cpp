#include "TableModel.h"

TableModel::TableModel(QObject* parent) :
    QAbstractListModel(parent), m_board(Board(10, 10)) {
    qDebug() << __PRETTY_FUNCTION__;
}

TableModel::TableModel(int width, int height) :
    QAbstractListModel(), m_board(Board(width, height)) {}


int TableModel::rowCount(const QModelIndex&) const {
    qDebug() << __PRETTY_FUNCTION__;
    qDebug() << m_board.width();
    return m_board.width() * m_board.height();
}


QVariant TableModel::data(const QModelIndex &index, int role) const {
    #define ROW m_board.getRow(index.row())
    #define COL m_board.getCol(index.row())

    if(index.isValid()) { return QVariant(); }

    switch (role) {
    case Roles::ColorRole:
        switch (m_board[ROW][COL]) {
            case CellType::Red:
                return QVariant(colors[0]);
            case CellType::Green:
                return QVariant(colors[1]);
            case CellType::Blue:
                return QVariant(colors[2]);
            case CellType::Yellow:
                return QVariant(colors[3]);
            default:
                return QVariant(colors[4]);
        }
    default:
        return QVariant();
    }

    #undef COL
    #undef ROW
}


QHash<int, QByteArray> TableModel::roleNames() const { return roles; }
