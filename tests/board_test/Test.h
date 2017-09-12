#ifndef TEST_H
#define TEST_H


#include <ostream>
using std::ostream;
#include <iostream>
using std::cout;
using std::endl;


#include <QTest>
#include <QObject>

#include "../../src/Board.h"


ostream& operator << (ostrem& os, const Board& board);


ostream& operator << (ostream& os, const Board& board) {
    for (const QList<CellType>& row: board) {
        for (CellType cell: row) {
            os <<
        }
    }
}


class BoardTest : public QObject {
    Q_OBJECT

    Board board;

public:
    BoardTest(const int width, const int height);
    ~BoardTest() override = default;

private slots:
    void reprTest();
};

#endif // TEST_H
