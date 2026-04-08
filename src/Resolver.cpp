#include "Resolver.h"
#include "Board.h"
#include <ctime> // Para calcular el tiempo de ejecución

set<Board> tree;
set<Board> usedBoards;


bool isUsedBoard(Board &b) {
    return usedBoards.find(b) != usedBoards.end();
}


void expandBoard(Board b){
	char solutionChar;
	if(canMoveUp(b)){
		Board b1;
		copyBoard(b, b1);
		solutionChar = moveUp(b1);
		b1.h = heuristica(b1);
		if(!isUsedBoard(b1)){
			addToSolution(b1, solutionChar);
			tree.insert(b1);
		}
	}
	if(canMoveDown(b)){
		Board b2;
		copyBoard(b, b2);
		solutionChar = moveDown(b2);
		b2.h = heuristica(b2);
		if(!isUsedBoard(b2)){
			addToSolution(b2, solutionChar);
			tree.insert(b2);
		}
	}
	if(canMoveLeft(b)){
		Board b3;
		copyBoard(b, b3);
		solutionChar = moveLeft(b3);
		b3.h = heuristica(b3);
		if(!isUsedBoard(b3)){
			addToSolution(b3, solutionChar);
			tree.insert(b3);
		}
	}
	if(canMoveRight(b)){
		Board b4;
		copyBoard(b, b4);
		solutionChar = moveRight(b4);
		b4.h = heuristica(b4);
		if(!isUsedBoard(b4)){
			addToSolution(b4, solutionChar);
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
	clock_t inicio = clock();
	int exploredNodes = 0;
    while(!tree.empty() && tree.begin()->h != 0){
		exploredNodes++;
		cout << "Proceso este estado: " << endl;
		showBoard(*tree.begin());
		cout << "h = " << tree.begin()->h << " | posZ = [" << tree.begin()->posZ[0] << "][" << tree.begin()->posZ[1] << "]" << " | posX = [" << tree.begin()->posX[0] << "][" << tree.begin()->posX[1] << "]" << endl;
		expandBestBoard();

    }

	//Cálculo del tiempo de búsqueda
	clock_t fin = clock();
    double duracion = double(fin - inicio) / CLOCKS_PER_SEC;

	if(tree.empty())
		cout << "No hay solucion" << endl;
	else
		cout << " La solucion es: " + tree.begin()->solution << endl;
	
	cout << "Nodos explorados: " << exploredNodes << endl;
	cout << "Tiempo de búsqueda: " << duracion*1000 << " ms" << endl;

}

void expandBoardAStar(Board b){
	char solutionChar;
	if(canMoveUp(b)){
		Board b1;
		copyBoard(b, b1);
		solutionChar = moveUp(b1);
		b1.h = heuristica(b1);
		b1.g++;
		if(!isUsedBoard(b1)){
			addToSolution(b1, solutionChar);
			tree.insert(b1);
		}
	}
	if(canMoveDown(b)){
		Board b2;
		copyBoard(b, b2);
		solutionChar = moveDown(b2);
		b2.h = heuristica(b2);
		b2.g++;
		if(!isUsedBoard(b2)){
			addToSolution(b2, solutionChar);
			tree.insert(b2);
		}
	}
	if(canMoveLeft(b)){
		Board b3;
		copyBoard(b, b3);
		solutionChar = moveLeft(b3);
		b3.h = heuristica(b3);
		b3.g++;
		if(!isUsedBoard(b3)){
			addToSolution(b3, solutionChar);
			tree.insert(b3);
		}
	}
	if(canMoveRight(b)){
		Board b4;
		copyBoard(b, b4);
		solutionChar = moveRight(b4);
		b4.h = heuristica(b4);
		b4.g++;
		if(!isUsedBoard(b4)){
			addToSolution(b4, solutionChar);
			tree.insert(b4);
		}
	}

}

void expandBestBoardAStar(){
	Board bestBorad = *tree.begin();
    tree.erase(tree.begin());

	usedBoards.insert(bestBorad);

    expandBoardAStar(bestBorad);
}

void resolveAStar(){	clock_t inicio = clock();
	int exploredNodes = 0;
    while(!tree.empty() && tree.begin()->h != 0){
		exploredNodes++;
		cout << "Proceso este estado: " << endl;
		showBoard(*tree.begin());
		cout << "f = " << tree.begin()->g + tree.begin()->h << " | posZ = [" << tree.begin()->posZ[0] << "][" << tree.begin()->posZ[1] << "]" << " | posX = [" << tree.begin()->posX[0] << "][" << tree.begin()->posX[1] << "]" << endl;
		expandBestBoardAStar();

    }

	//Cálculo del tiempo de búsqueda
	clock_t fin = clock();
    double duracion = double(fin - inicio) / CLOCKS_PER_SEC;

	if(tree.empty())
		cout << "No hay solucion" << endl;
	else
		cout << " La solucion es: " + tree.begin()->solution << endl;
	
	cout << "Nodos explorados: " << exploredNodes << endl;
	cout << "Tiempo de búsqueda: " << duracion*1000 << " ms" << endl;

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
