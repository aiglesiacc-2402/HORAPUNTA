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

set<Board> tree;


void expandBestBoard();

void resolve();

#endif