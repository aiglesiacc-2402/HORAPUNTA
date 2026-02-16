#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
const int MAXTAM = 6;
char board[MAXTAM][MAXTAM];
int posX[2];
const string file = "HORAPUNTA3.txt";

void updateXCoords(int i, int j){
	posX[0] = i;
	posX[1] = j;
}

void showBoard(){
	for(int i = 0; i < MAXTAM; i++){
		for(int j = 0; j < MAXTAM; j++){
			cout << board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool canMoveLeft(){
	int i = posX[0];
	int j = posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de la IZQUIERDA
	if(j==0){ // Si X está en el límite IZQUIERDO no podemos mover lo de la IZQUIERDA
		possible = false;
	}
	else{
		char car = board[i][j-1];
		// Si los caracteres de ARRIBA y ABAJO de car son distintos a car, entonces podré mover
		if(i != 0 && board[i-1][j-1] == car){ // Si no puedo mirar ARRIBA o lo que hay ARRIBA es igual
			possible = false;
		}
		else if(i != MAXTAM-1 && board[i+1][j-1] == car){ // Si no puedo mirar ABAJO o lo que hay ABAJO es igual
			possible = false;
		}
	}

	return possible;
}

bool canMoveRight(){
	int i = posX[0];
	int j = posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de la DERECHA
	if(j==MAXTAM-1){ // Si X está en el límite DERECHO no podemos mover lo de la DERECHA
		possible = false;
	}
	else{
		char car = board[i][j+1];
		// Si los caracteres de ARRIBA y ABAJO de car son distintos a car, entonces podré mover
		if(i != 0 && board[i-1][j+1] == car){ // Si no puedo mirar ARRIBA o lo que hay ARRIBA es igual
			possible = false;
		}
		else if(i != MAXTAM-1 && board[i+1][j+1] == car){ // Si no puedo mirar ABAJO o lo que hay ABAJO es igual
			possible = false;
		}
	}

	return possible;
}

bool canMoveUp(){
	int i = posX[0];
	int j = posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de ARRIBA
	if(i==0){ // Si X está en el límite SUPERIOR no podemos mover lo de ARRIBA
		possible = false;
	}
	else{
		char car = board[i-1][j];
		// Si los caracteres de IZQUIERDA y DERECHA de car son distintos a car, entonces podré mover
		if(j != 0 && board[i-1][j-1] == car){ // Si no puedo mirar a la IZQUIERDA o lo que hay a la IZQUIERDA es igual
			possible = false;
		}
		else if(j != MAXTAM-1 && board[i-1][j+1] == car){ // Si no puedo mirar a la DERECHA o lo que hay a la DERECHA es igual
			possible = false;
		}
	}

	return possible;
}

bool canMoveDown(){
	int i = posX[0];
	int j = posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de ABAJO
	if(i==MAXTAM-1){ // Si X está en el límite INFERIOR no podemos mover lo de ABAJO
		possible = false;
	}
	else{
		char car = board[i-1][j];
		// Si los caracteres de IZQUIERDA y DERECHA de car son distintos a car, entonces podré mover
		if(j != 0 && board[i-1][j-1] == car){ // Si no puedo mirar a la IZQUIERDA o lo que hay a la IZQUIERDA es igual
			possible = false;
		}
		else if(j != MAXTAM-1 && board[i-1][j+1] == car){ // Si no puedo mirar a la DERECHA o lo que hay a la DERECHA es igual
			possible = false;
		}
	}

	return possible;
}

bool canMove(){
	return canMoveDown() || canMoveRight() || canMoveUp() || canMoveLeft();
}

// Pre: puedo mover a la izquierda de la x
char moveLeft(){
	int i = posX[0];
	int j = posX[1];
	char car = board[i][j-1];
	int size = 1;
	while((j-size) >= 0 && board[i][j-size]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	board[i][j-size] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(i, j-size); // Actualizamos la posición de la X

	return car;
}

// Pre: puedo mover a la derecha de la x
char moveRight(){
	int i = posX[0];
	int j = posX[1];
	char car = board[i][j+1];
	int size = 1;
	while((j+size) < MAXTAM && board[i][j+size]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	board[i][j+size] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(i, j+size); // Actualizamos la posición de la X

	return car;
}

// Pre: puedo mover arriba de la x
char moveUp(){
	int i = posX[0];
	int j = posX[1];
	char car = board[i-1][j];
	int size = 1;
	while((i-size) >= 0 && board[i-size][j]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	board[i-size][j] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(i-size, j); // Actualizamos la posición de la X

	return car;
}

// Pre: puedo mover arriba de la x
char moveDown(){
	int i = posX[0];
	int j = posX[1];
	char car = board[i+1][j];
	int size = 1;
	while((i+size) < MAXTAM && board[i+size][j]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	board[i+size][j] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(i+size, j); // Actualizamos la posición de la X

	return car;
}

int main(){
	ifstream finalFile;
	finalFile.open("BOARDS/" + file);
	string row;

	if(finalFile.is_open()){
		for(int i = 0; i < MAXTAM; i++){
            getline(finalFile, row);
			for(int j = 0; j < MAXTAM; j++){
			    board[i][j] = row[j*2];
				if(board[i][j] == 'X'){
					updateXCoords(i, j);
				}
			}
		}
		finalFile.close();
		showBoard();
		if(canMoveUp()){
			cout<<"Up"<<endl;
			moveUp();
			showBoard();
		}
		if(canMoveDown()){
			cout<<"Down"<<endl;
			moveDown();
			showBoard();
		}
		if(canMoveLeft()){
			cout<<"Left"<<endl;
			moveLeft();
			showBoard();
		}
		if(canMoveRight()){
			cout<<"Right"<<endl;
			moveRight();
			showBoard();
		}
	} else {
		cout <<"Fichero de carga no encontrado (<HORAPUNTA>/" << file << ")" <<endl;
	}

	return 0;
}