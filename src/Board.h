#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

const int MAX_ROWS = 6;
const int MAX_COLUMNS = 6;

struct Board{
    char board[MAX_ROWS][MAX_COLUMNS];
    int posX[2];
    int posZ[2];
    string solution;
    int h;
    int g=0; // iniciado a 0 de base para prevenir problemas

    bool operator<(const Board& other) const {
        int f = g+h;
        int otherF = other.g + other.h;
        if (f != otherF) return f<otherF; 
        else{
            // Desempate por contenido
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLUMNS; j++) {
                    if (board[i][j] != other.board[i][j])
                        return board[i][j] < other.board[i][j];
                }
            }
        }
        return false;
    }
    bool operator>(const Board& other) const {
        return (h+g) > (other.h + other.g); 
    }
    bool operator==(const Board& other) const {
        bool equals = true;
        for(int i = 0; i <MAX_ROWS ; i++){
            for(int j = 0; j <MAX_COLUMNS ; j++){
                if(board[i][j] != other.board[i][j]){
                    equals = false;
                }
            }
        }
        return equals; 
    }
    bool operator!=(const Board& other) const {
        return !(*this == other); 
    }
};

int heuristica(Board &b);

void loadBoard(Board &b, string file);

void updateXCoords(Board &b, int i, int j);

void updateZCoords(Board &b, int i, int j);

void copyBoard(Board b, Board &b2);

void showBoard(const Board b);

void addToSolution(Board &b, char toAdd);

bool canMove(const Board &b);

bool canMoveUp(const Board b);

bool canMoveDown(const Board b);

bool canMoveLeft(const Board b);

bool canMoveRight(const Board b);

char moveUp(Board &b);

char moveDown(Board &b);

char moveLeft(Board &b);

char moveRight(Board &b);

bool isUsedBoard(Board &b);

#endif /* BOARD_H_ */