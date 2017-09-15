#ifndef TABLEMODEL_H
#define TABLEMODEL_H


#include <QColor>
#include <QList>
#include <QVariant>
#include <QAbstractListModel>
#include <QtGlobal>

#include "Board.h"


class TableModel : public QAbstractListModel {
    using Colors = QList<QColor>;

public:
    TableModel(QObject* parent=nullptr);
    TableModel(int with, int height);
    ~TableModel() = default;

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex& index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE int _w() const {
        qDebug() << __PRETTY_FUNCTION__;
        return m_board.width();
    }
    Q_INVOKABLE int _h() const { return m_board.height(); }

public:
    enum Roles {
        ColorRole = Qt::UserRole + 1,
    };

private:
    Board m_board;

    QHash<int, QByteArray> roles = {
        {Roles::ColorRole, "color"},
    };

    Colors colors = {
        QColor(255,   0,   0),
        QColor(  0, 255,   0),
        QColor(  0,   0, 255),
        QColor(255, 255,  51),
        QColor(  0,   0,   0, 0)
    };
};

#endif // TABLEMODEL_H
