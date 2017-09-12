#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QColor>
#include <QDebug>
#include <QTime>
#include <QtGlobal>


inline int randomInt(const int min, const int max);


enum class CellType {
    Empty = 0,
    Red = 1,
    Green = 2,
    Blue = 3,
};


class Board
{
public:
    Board(const int width, const int height);
    ~Board() = default;

    QList<QList<CellType>> board() const { return m_board; }

private:
    void init();

private:
    int m_width,
        m_height;

    QList<QList<CellType>> m_board;

    QList<CellType> cell = {
        CellType::Red,
        CellType::Green,
        CellType::Blue
    };
};


inline int randomInt(const int min, const int max) {
    qsrand(QTime::currentTime().msec());
    return qrand() % max + min;
}

#endif // BOARD_H
