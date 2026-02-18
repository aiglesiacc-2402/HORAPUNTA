#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

const int MAX_ROWS = 6;
const int MAX_COLUMNS = 6;

struct Board{
    char board[6][6];
    int posX[2];
    string solution;
};

void loadBoard(Board &b, string file);

void updateXCoords(Board &b, int i, int j);

void copyBoard(Board b, Board &b2);

void showBoard(const Board b);

void addToSolution(Board &b, char toAdd);

bool canMove(const Board b);

bool canMoveUp(const Board b);

bool canMoveDown(const Board b);

bool canMoveLeft(const Board b);

bool canMoveRight(const Board b);

char moveUp(Board &b);

char moveDown(Board &b);

char moveLeft(Board &b);

char moveRight(Board &b);

#endif /* BOARD_H_ */