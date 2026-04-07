#include "HillClimbing.h"

void SimpleHillClimbingR(Board &b, int &nodes){
    char solutionChar;
    cout << "Proceso este estado:" << endl;
    showBoard(b);
    cout << "h = " << b.h << " | posZ = [" << b.posZ[0] << "][" << b.posZ[1] << "]" << " | posX = [" << b.posX[0] << "][" << b.posX[1] << "]" << endl;

    bool improved = false;
    if(b.h != 0){
        if(!improved && canMoveUp(b)){
            nodes++;
            Board b1;
            copyBoard(b, b1);
            solutionChar = moveUp(b1);
            b1.h = heuristica(b1);
            if(b1.h < b.h){
                improved = true;
                addToSolution(b1, solutionChar);
                b = b1;
                SimpleHillClimbingR(b, nodes);
            }
        }
        if(!improved && canMoveDown(b)){
            nodes++;
            Board b2;
            copyBoard(b, b2);
            solutionChar = moveDown(b2);
            b2.h = heuristica(b2);
            if(b2.h < b.h){
                improved = true;
                addToSolution(b2, solutionChar);
                b = b2;
                SimpleHillClimbingR(b, nodes);
            }
        }
        if(!improved && canMoveLeft(b)){
            nodes++;
            Board b3;
            copyBoard(b, b3);
            solutionChar = moveLeft(b3);
            b3.h = heuristica(b3);
            if(b3.h < b.h){
                improved = true;
                addToSolution(b3, solutionChar);
                b = b3;
                SimpleHillClimbingR(b, nodes);
            }
        }
        if(!improved && canMoveRight(b)){
            nodes++;
            Board b4;
            copyBoard(b, b4);
            solutionChar = moveRight(b4);
            b4.h = heuristica(b4);
            if(b4.h < b.h){
                improved = true;
                addToSolution(b4, solutionChar);
                b = b4;
                SimpleHillClimbingR(b, nodes);
            }
        }
    }
}

void SimpleHillClimbing(Board &b){
    clock_t start = clock();
    int nodes = 0;
    if(b.h != 0 && canMove(b)){
        nodes++;
        SimpleHillClimbingR(b, nodes);
    }
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    if(nodes == 0 || b.h != 0)
        cout << "No hay solucion" << endl;
    else
        cout << " La solucion es: " + b.solution << endl;
    cout << "Nodos explorados: " << nodes << endl;
	cout << "Tiempo de búsqueda: " << time*1000 << " ms" << endl;
}

void SteepestAscentHillClimbingR(Board &b, int &nodes){
    char solutionChar;
    cout << "Proceso este estado:" << endl;
    showBoard(b);
    cout << "h = " << b.h << " | posZ = [" << b.posZ[0] << "][" << b.posZ[1] << "]" << " | posX = [" << b.posX[0] << "][" << b.posX[1] << "]" << endl;

    Board b1;
    Board b2;
    Board b3;
    Board b4;
    Board better;
    char betterChar;

    if(b.h != 0){

        int h = INT_MAX;

        if(canMoveUp(b)){
            nodes++;
            copyBoard(b, b1);
            solutionChar = moveUp(b1);
            b1.h = heuristica(b1);
            if(b1.h < b.h && b1.h < h){
                h = b1.h;
                better = b1;
                betterChar = solutionChar;
            }
        }
        if(canMoveDown(b)){
            nodes++;
            copyBoard(b, b2);
            solutionChar = moveDown(b2);
            b2.h = heuristica(b2);
            if(b2.h < b.h && b2.h < h){
                h = b2.h;
                better = b2;
                betterChar = solutionChar;
            }
        }
        if(canMoveLeft(b)){
            nodes++;
            copyBoard(b, b3);
            solutionChar = moveLeft(b3);
            b3.h = heuristica(b3);
            if(b3.h < b.h && b3.h < h){
                h = b3.h;
                better = b3;
                betterChar = solutionChar;
            }
        }
        if(canMoveRight(b)){
            nodes++;
            copyBoard(b, b4);
            solutionChar = moveRight(b4);
            b4.h = heuristica(b4);
            if(b4.h < b.h && b4.h < h){
                h = b4.h;
                better = b4;
                betterChar = solutionChar;
            }
        }
        if(h < b.h){
            b = better;
            addToSolution(b, betterChar);
            SteepestAscentHillClimbingR(b, nodes);
        }
    }
}

void SteepestAscentHillClimbing(Board b){
    clock_t start = clock();
    int nodes = 0;
    if(b.h != 0 && canMove(b)){
        nodes++;
        SteepestAscentHillClimbingR(b, nodes);
    }
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    if(nodes == 0 || b.h != 0)
        cout << "No hay solucion" << endl;
    else
        cout << " La solucion es: " + b.solution << endl;
    cout << "Nodos explorados: " << nodes << endl;
	cout << "Tiempo de búsqueda: " << time*1000 << " ms" << endl;
}
