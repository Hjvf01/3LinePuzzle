#include "Board.h"


Board::Board(const int width, const int height) :
    m_width(width), m_height(height)
{
    init();
}


void Board::init()
{
    for (int i = 0; i < m_height; ++i) {
        m_board.append(QList<CellType>());
        for (int j = 0; j < m_width; ++j) {
            m_board[i].append(cell[randomInt(0, cell.size())]);
        }
    }
}
