#ifndef TABLEMODEL_H
#define TABLEMODEL_H


#include <QColor>
#include <QList>
#include <QAbstractListModel>
#include <QtGlobal>


class TableModel : public QAbstractListModel
{
    using Colors = QList<QColor>;

public:
    TableModel(QObject* parent=nullptr);
    TableModel(int with, int height);
    ~TableModel() = default;

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex& index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public:
    enum Roles
    {
        ColorRole = Qt::UserRole + 1,
    };

private:
    int m_width;
    int m_height;

    QHash<int, QByteArray> roles = {
        {Roles::ColorRole, "color"},
    };

    Colors colors = {
        QColor(255, 0, 0),
        QColor(0, 255, 0),
        QColor(0, 0, 255),
    };
};

#endif // TABLEMODEL_H
