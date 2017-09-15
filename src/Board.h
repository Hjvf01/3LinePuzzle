#ifndef BOARD_H
#define BOARD_H

#include <cassert>
#include <functional>
using std::function;
#include <algorithm>
using std::swap;

#include <QList>
#include <QColor>
#include <QDebug>
#include <QTime>
#include <QtGlobal>


inline function<int()> randomInt(const int min, const int max);


struct Point {
    int row;
    int col;
};


enum class CellType {
    Empty = 0,
    Red = 1,
    Green = 2,
    Blue = 3,
    Yellow = 4,
};


class Board {
public:
    Board(const int width, const int height);
    Board(const QList<QList<CellType>>& board);
    ~Board() = default;

    QList<QList<CellType>> board() const { return m_board; }
    const QList<CellType>& operator [] (const int i) const;
    QList<CellType>& operator [] (const int i);

    int height() const { return m_height; }
    int width() const { return m_width; }

    int getRow(const int i) const { return i / m_width; }
    int getCol(const int i) const { return i % m_width; }

    bool canSwap(const Point& p1, const Point& p2) const;

private:
    void init();

    bool checkHorizontal(const Point& point, const CellType& color) const;
    bool checkVertical(const Point& point, const CellType& color) const;

private:
    int m_width,
        m_height;

    QList<QList<CellType>> m_board;

    QList<CellType> cell = {
        CellType::Red,
        CellType::Green,
        CellType::Blue,
        CellType::Yellow,
    };
};


inline function<int()> randomInt(const int min, const int max) {
    qsrand(QTime::currentTime().msec());

    return [min, max]() -> int {
        return qrand() % max + min;
    };
}

#endif // BOARD_H
