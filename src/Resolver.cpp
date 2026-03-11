#include "Resolver.h"
#include "Board.h"

set<Board> tree;
set<Board> usedBoards;


bool isUsedBoard(Board &b) {
    for (const Board& b_usado : usedBoards) {
        if (b_usado == b) { 
            return true;
        }
    }
    return false;
}


void expandBoard(Board b){
	char solutionChar;
	if(canMoveUp(b)){
		Board b1;
		copyBoard(b, b1);
		solutionChar = moveUp(b1);
		if(!isUsedBoard(b1)){
			addToSolution(b1, solutionChar);
			b1.h = heuristica(b1);
			tree.insert(b1);
		}
	}
	if(canMoveDown(b)){
		Board b2;
		copyBoard(b, b2);
		solutionChar = moveDown(b2);
		if(!isUsedBoard(b2)){
			addToSolution(b2, solutionChar);
			b2.h = heuristica(b2);
			tree.insert(b2);
		}
	}
	if(canMoveLeft(b)){
		Board b3;
		copyBoard(b, b3);
		solutionChar = moveLeft(b3);
		if(!isUsedBoard(b3)){
			addToSolution(b3, solutionChar);
			b3.h = heuristica(b3);
			tree.insert(b3);
		}
	}
	if(canMoveRight(b)){
		Board b4;
		copyBoard(b, b4);
		solutionChar = moveRight(b4);
		if(!isUsedBoard(b4)){
			addToSolution(b4, solutionChar);
			b4.h = heuristica(b4);
			tree.insert(b4);
		}
	}
}


void expandBestBoard(){
    Board bestBorad = *tree.begin();
    tree.erase(tree.begin());

	usedBoards.insert(bestBorad);

    expandBoard(bestBorad);
}


void resolve(){
    while(!tree.empty() && tree.begin()->h != 0){
		cout << "Proceso este estado: " << endl;
		showBoard(*tree.begin());
		expandBestBoard();

    }
	if(tree.empty())
		cout << "No hay solución";
	else
		cout << " La solución es: " + tree.begin()->solution;
}

void prueba(){
	expandBestBoard();
	for(Board b: tree){
		showBoard(b);
		cout <<"h = " << b.h <<  endl;
	}
	cout << "Elimino el mejor" << endl;
	tree.erase(tree.begin());
	for(Board b: tree){
		showBoard(b);
		cout <<"h = " << b.h <<  endl;
	}
	cout << "Elimino el mejor" << endl;
	tree.erase(tree.begin());
	for(Board b: tree){
		showBoard(b);
		cout <<"h = " << b.h <<  endl;
	}
	cout << "Elimino el mejor" << endl;
	tree.erase(tree.begin());
	for(Board b: tree){
		showBoard(b);
		cout <<"h = " << b.h <<  endl;
	}
	
}
