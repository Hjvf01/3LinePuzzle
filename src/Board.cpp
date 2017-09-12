#include "Board.h"


Board::Board(const int width, const int height) :
    m_width(width), m_height(height)
{
    init();
}


void Board::init()
{
    auto random_gen = randomInt(0, cell.size());
    for (int i = 0; i < m_height; ++i) {
        m_board.append(QList<CellType>());
        for (int j = 0; j < m_width; ++j) {
            m_board[i].append(cell[random_gen()]);
        }
    }

    for(int i = 0; i < (int)((m_width * m_height) * 0.5); i++) {
        std::swap(
            m_board[random_gen()][random_gen()],
            m_board[random_gen()][random_gen()]
       );
    }
}


const QList<CellType>& Board::operator [] (const int i) const {
    assert(i <= m_board.size() - 1);
    return m_board[i];
}


QList<CellType>& Board::operator [] (const int i) {
    assert(i <= m_board.size() - 1);
    return m_board[i];
}


bool Board::canSwap(const Point &p1, const Point &p2) const {
    return (
        checkHorizontal(p1) ||
        checkHorizontal(p2) ||
        checkVertical(p1)   ||
        checkVertical(p2)
    );
}


bool Board::checkHorizontal(const Point &point) const {
    CellType color = m_board[point.row][point.col];
    return true;
}


bool Board::checkVertical(const Point &point) const {
    return true;
}
