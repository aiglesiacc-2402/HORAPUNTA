#include "Board.h"
#inlcude "Resolver.h"

const string file = "HORAPUNTA1.txt";

int main(){
    Board b;
    loadBoard(b, file);
	tree.insert(b);
    showBoard(b);
	cout<<endl;
	resolve();
    /*if(canMoveUp(b)){
		Board b1;
		copyBoard(b, b1);
		addToSolution(b1, moveUp(b1));
		showBoard(b1);
		cout<<"Solution:"<<b1.solution<< " with h'= " << b1.h << endl;
		cout<<endl;
	}
	if(canMoveDown(b)){
		Board b2;
		copyBoard(b, b2);
		addToSolution(b2, moveDown(b2));
		showBoard(b2);
		cout<<"Solution:"<<b2.solution<< " with h'= " << b2.h << endl;
		cout<<endl;
	}
	if(canMoveLeft(b)){
		Board b3;
		copyBoard(b, b3);
		addToSolution(b3, moveLeft(b3));
		showBoard(b3);
		cout<<"Solution:"<<b3.solution<< " with h'= " << b3.h << endl;
		cout<<endl;
	}
	if(canMoveRight(b)){
		Board b4;
		copyBoard(b, b4);
		addToSolution(b4, moveRight(b4));
		showBoard(b4);
		cout<<"Solution:"<<b4.solution<< " with h'= " << b4.h << endl;
		cout<<endl;
	}*/
    return 0;
}