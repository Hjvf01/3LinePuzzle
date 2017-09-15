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


QDebug& operator << (QDebug& d, const CellType& cell) {
    switch (cell) {
        case CellType::Empty: return d << "E";
        case CellType::Red: return d << "R";
        case CellType::Green: return d << "G";
        case CellType::Yellow: return d << "Y";
        default: return d << "B";
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


BoardTest::BoardTest(const int _width, const int _height) :
    QObject(), board(Board(_width, _height)), width(_width), height(_height) {}


void BoardTest::reprTest() {
    cout << board << endl;
    QVERIFY(true);
}


void BoardTest::getRowTest() {
    int index = 0;
    for (int i = 0; i < height; ++i) {
        qDebug() << "row: " << i << "\t" << board[i];
        for (int j = 0; j < width; ++j) {
            QVERIFY(board.getRow(index) == i);
            index++;
        }
    }
}


void BoardTest::getColTest() {
    int index = 0;
    for (int i = 0; i < height; ++i) {
        qDebug() << "row: " << i << "\t" << board[i];
        for (int j = 0; j < width; ++j) {
            QVERIFY(board.getCol(index) == j);
            index++;
        }
    }
}


void BoardTest::canMoveTest() {
    #define Y CellType::Yellow
    #define R CellType::Red
    #define G CellType::Green
    #define B CellType::Blue

    QList<QList<CellType>> _table = {
        {Y, R},
        {Y, G},
        {B, Y},
        {B, G},
    };
    Board _board = Board(_table);
    cout << endl;
    cout << _board << endl;

    QVERIFY(board.canSwap(Point{2, 0}, Point{2, 1}));

    #undef Y
    #undef R
    #undef G
    #undef B
}


void BoardTest::bench() {
    auto randI = randomInt(0, width * height - 1);
    QBENCHMARK { board.getRow(randI()); }
    QBENCHMARK { board.getRow(randI()); }
}
