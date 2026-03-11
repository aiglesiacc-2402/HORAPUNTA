#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <utility>
#include <cmath>

#include "Board.h"


using namespace std;

#ifndef RESOLVER_H_
#define RESOLVER_H_

extern set<Board> tree;
extern set<Board> usedBoards;

bool isUsedBoard(Board &b);

void expandBoard(Board b);

void expandBestBoard();

void resolve();

void prueba();



#endif