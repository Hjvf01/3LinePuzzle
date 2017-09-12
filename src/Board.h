#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QColor>
#include <QtGlobal>


enum class CellType {
    Empty = 0,
    Red = 1,
    Green = 2,
    Blue = 3,
};


class Board
{
public:
    Board();

private:
    QList<CellType> m_data;
};

#endif // BOARD_H
