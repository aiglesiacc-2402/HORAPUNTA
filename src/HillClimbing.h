#include "Board.h"
#include <climits>
#include <ctime>

#ifndef HILLCLIMBING_H_
#define HILLCLIMBING_H_

void SimpleHillClimbingR(Board &b, int &nodes);

void SimpleHillClimbing(Board &b);

void SteepestAscentHillClimbingR(Board &b, int &nodes);

void SteepestAscentHillClimbing(Board b);

#endif