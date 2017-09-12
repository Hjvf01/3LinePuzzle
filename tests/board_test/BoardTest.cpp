#include "Test.h"


ostream& operator << (ostream& os, const CellType& cell) {
    switch (cell) {
        case CellType::Empty: return os << "E";
        case CellType::Red: return os << "R";
        case CellType::Green: return os << "G";
        case CellType::Yellow: return os << "Y";
        default: return os << "B";
    }
}


ostream& operator << (ostream& os, const Board& board) {
    for (int i = 0; i < board.height(); ++i) {
        for (int j = 0; j < board.width(); ++j) {
            os << board[i][j];
        }
        os << endl;
    }
    return os;
}


BoardTest::BoardTest(const int width, const int height) :
    QObject(), board(Board(width, height)) {}


void BoardTest::reprTest() {
    cout << board << endl;
}
