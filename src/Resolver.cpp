#include "Resolver.h"
#include "Board.h"


void expandBestBoard(){
    Board bestBorad = *tree.begin();
    tree.erase(tree.begin());

    if(canMoveUp(bestBorad)){
		Board b1;
		copyBoard(bestBorad, b1);
		addToSolution(b1, moveUp(b1));
        tree.insert(b1);
	}
	if(canMoveDown(bestBorad)){
		Board b2;
		copyBoard(bestBorad, b2);
		addToSolution(b2, moveDown(b2));
		tree.insert(b2);
	}
	if(canMoveLeft(bestBorad)){
		Board b3;
		copyBoard(bestBorad, b3);
		addToSolution(b3, moveLeft(b3));
		tree.insert(b3);
	}
	if(canMoveRight(bestBorad)){
		Board b4;
		copyBoard(bestBorad, b4);
		addToSolution(b4, moveRight(b4));
		tree.insert(b4);
	}
}


void resolve(){
    while(tree.begin()->h != 0){
        expandBestBoard();
    }
    showBoard(*tree.begin());
}

