QT       += testlib

TARGET = BoardTest
CONFIG   += console c++14
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES +=\
    BoardTest.cpp\
    ../../src/Board.cpp \
    main.cpp

HEADERS +=\
    ../../src/Board.h\
    Test.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"
