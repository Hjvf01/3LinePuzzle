#include "Test.h"


BoardTest::BoardTest(const int width, const int height) :
    QObject(), board(Board(width, height)) {}
