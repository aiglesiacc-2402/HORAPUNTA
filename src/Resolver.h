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

// Estos tres métodos de A* duplican mucho codigo de los 3 métodos anteriores por velocidad y facilidad a la hora de crearlos pero no importa
void expandBoardAStar(Board b);

void expandBestBoardAStar();

void resolveAStar();

void prueba();



#endif