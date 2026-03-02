#include "Resolver.h"
#include "Board.h"


void expandBestBoard(){
    Board bestBorad = *tree.begin();
    tree.erase(tree.begin());

    if(canMoveUp(b)){
		Board b1;
		copyBoard(b, b1);
		addToSolution(b1, moveUp(b1));
        tree.insert(b1);
	}
	if(canMoveDown(b)){
		Board b2;
		copyBoard(b, b2);
		addToSolution(b2, moveDown(b2));
		tree.insert(b2);
	}
	if(canMoveLeft(b)){
		Board b3;
		copyBoard(b, b3);
		addToSolution(b3, moveLeft(b3));
		tree.insert(b3);
	}
	if(canMoveRight(b)){
		Board b4;
		copyBoard(b, b4);
		addToSolution(b4, moveRight(b4));
		tree.insert(b4);
	}
}


void resolve(){
    while(*tree.begin().h != 0){
        expandBestBoard();
    }
    showBoard(*tree.begin());
}

