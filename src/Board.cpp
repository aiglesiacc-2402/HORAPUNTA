#include "Board.h"

// Calcula la suma de la distancia de Z al borde y la distancia de X a Z
int heuristica(Board &b){
	int max_dist_H = ceil(MAX_COLUMNS/2);
	int max_dist_V = ceil(MAX_ROWS/2);
	int disX = 0;
	// Calcular distancia de Z al borde
	int disZ = min((b.posZ[0] % max_dist_H), (b.posZ[1] % max_dist_V));

	// Calcular distancia de X a Z
	if(disZ != 0){
		if(b.posX[0] >= b.posZ[0]){
			disX = b.posX[0]-b.posZ[0];
		}else{
			disX = b.posZ[0]-b.posX[0];
		}
		if(b.posX[1] >= b.posZ[1]){
			disX += b.posX[1]-b.posZ[1];
		}else{
			disX += b.posZ[1]-b.posX[1];
		}
	}
	return disX+disZ;
}

void loadBoard(Board &b, string file){
    ifstream finalFile;
	finalFile.open("BOARDS/" + file);
	string row;

	if(finalFile.is_open()){
		for(int i = 0; i < 6; i++){
            getline(finalFile, row);
			for(int j = 0; j < 6; j++){
			    b.board[i][j] = row[j*2];
				if(row[j*2] == 'X'){
					b.posX[0] = i;
					b.posX[1] = j;
				}
				if(row[j*2] == 'Z'){
					b.posZ[0] = i;
					b.posZ[1] = j;
				}
			}
		}
		b.h = heuristica(b);
		finalFile.close();
	} else {
		cout <<"Fichero de carga no encontrado (<HORAPUNTA>/" << file << ")" <<endl;
	}
}

void updateXCoords(Board &b, int i, int j){
	b.posX[0] = i;
	b.posX[1] = j;
}

void updateZCoords(Board &b, int i, int j){
	b.posZ[0] = i;
	b.posZ[1] = j;
}
void copyBoard(Board b, Board &b2){
	for(int i = 0; i < MAX_ROWS; i++){
		for(int j = 0; j < MAX_COLUMNS; j++){
			b2.board[i][j] = b.board[i][j];
		}
	}
	for(int i = 0; i < 2; i++){
		b2.posX[i] = b.posX[i];
		b2.posZ[i] = b.posZ[i];
	}
	b2.solution = b.solution;
	b2.h = b.h;
}

void showBoard(const Board b){
    for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			cout << b.board[i][j]<<" ";
		}
		cout<<endl;
	}
}

void addToSolution(Board &b, char toAdd){
	b.solution = b.solution + " " + toAdd;
}

bool canMove(const Board &b){
	return canMoveUp(b) || canMoveDown(b) || canMoveLeft(b) || canMoveRight(b);
}


bool canMoveUp(const Board b){
	int i = b.posX[0];
	int j = b.posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de ARRIBA
	if(i==0){ // Si X está en el límite SUPERIOR no podemos mover lo de ARRIBA
		possible = false;
	}
	else{
		char car = b.board[i-1][j];
		// Si los caracteres de IZQUIERDA y DERECHA de car son distintos a car, entonces podré mover
		if(j != 0 && b.board[i-1][j-1] == car){ // Si no puedo mirar a la IZQUIERDA o lo que hay a la IZQUIERDA es igual
			possible = false;
		}
		else if(j != MAX_COLUMNS-1 && b.board[i-1][j+1] == car){ // Si no puedo mirar a la DERECHA o lo que hay a la DERECHA es igual
			possible = false;
		}
	}
	return possible;
}

bool canMoveDown(const Board b){
	int i = b.posX[0];
	int j = b.posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de ABAJO
	if(i==MAX_ROWS-1){ // Si X está en el límite INFERIOR no podemos mover lo de ABAJO
		possible = false;
	}
	else{
		char car = b.board[i+1][j];
		// Si los caracteres de IZQUIERDA y DERECHA de car son distintos a car, entonces podré mover
		if(j != 0 && b.board[i+1][j-1] == car){ // Si no puedo mirar a la IZQUIERDA o lo que hay a la IZQUIERDA es igual
			possible = false;
		}
		else if(j != MAX_COLUMNS-1 && b.board[i+1][j+1] == car){ // Si no puedo mirar a la DERECHA o lo que hay a la DERECHA es igual
			possible = false;
		}
	}

	return possible;
}

bool canMoveLeft(const Board b){
	int i = b.posX[0];
	int j = b.posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de la IZQUIERDA
	if(j==0){ // Si X está en el límite IZQUIERDO no podemos mover lo de la IZQUIERDA
		possible = false;
	}
	else{
		char car = b.board[i][j-1];
		// Si los caracteres de ARRIBA y ABAJO de car son distintos a car, entonces podré mover
		if(i != 0 && b.board[i-1][j-1] == car){ // Si no puedo mirar ARRIBA o lo que hay ARRIBA es igual
			possible = false;
		}
		else if(i != MAX_ROWS-1 && b.board[i+1][j-1] == car){ // Si no puedo mirar ABAJO o lo que hay ABAJO es igual
			possible = false;
		}
	}

	return possible;
}

bool canMoveRight(const Board b){
	int i = b.posX[0];
	int j = b.posX[1];
	// Supongo que puedo mover y busco los contraargumentos
	bool possible = true;
	// Miro qué letra representa al coche de la DERECHA
	if(j==MAX_COLUMNS-1){ // Si X está en el límite DERECHO no podemos mover lo de la DERECHA
		possible = false;
	}
	else{
		char car = b.board[i][j+1];
		// Si los caracteres de ARRIBA y ABAJO de car son distintos a car, entonces podré mover
		if(i != 0 && b.board[i-1][j+1] == car){ // Si no puedo mirar ARRIBA o lo que hay ARRIBA es igual
			possible = false;
		}
		else if(i != MAX_ROWS-1 && b.board[i+1][j+1] == car){ // Si no puedo mirar ABAJO o lo que hay ABAJO es igual
			possible = false;
		}
	}

	return possible;
}

bool canMove(const Board b){
	return canMoveDown(b) || canMoveRight(b) || canMoveUp(b) || canMoveLeft(b);
}

// Pre: puedo mover arriba de la x
char moveUp(Board &b){
	int i = b.posX[0];
	int j = b.posX[1];
	char car = b.board[i-1][j];
	int size = 1;
	while((i-size) >= 0 && b.board[i-size][j]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	b.board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	b.board[i-size][j] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(b, i-size, j); // Actualizamos la posición de la X
	if (car == 'Z'){
		updateZCoords(b, i, j); // Actualizamos la posición de la Z
	}
	
	return car;
}

// Pre: puedo mover arriba de la x
char moveDown(Board &b){
	int i = b.posX[0];
	int j = b.posX[1];
	char car = b.board[i+1][j];
	int size = 1;
	while((i+size) < MAX_ROWS && b.board[i+size][j]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	b.board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	b.board[i+size][j] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(b, i+size, j); // Actualizamos la posición de la X
	if (car == 'Z'){
		updateZCoords(b, i, j); // Actualizamos la posición de la Z
	}

	return car;
}

// Pre: puedo mover a la izquierda de la x
char moveLeft(Board &b){
	int i = b.posX[0];
	int j = b.posX[1];
	char car = b.board[i][j-1];
	int size = 1;
	while((j-size) >= 0 && b.board[i][j-size]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	b.board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	b.board[i][j-size] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(b, i, j-size); // Actualizamos la posición de la X
	if (car == 'Z'){
		updateZCoords(b, i, j); // Actualizamos la posición de la Z
	}

	return car;
}

// Pre: puedo mover a la derecha de la x
char moveRight(Board &b){
	int i = b.posX[0];
	int j = b.posX[1];
	char car = b.board[i][j+1];
	int size = 1;
	while((j+size) < MAX_COLUMNS && b.board[i][j+size]==car){ // Buscamos el tamanio del coche
		size++;
	}
	size--; // Pero tenemos que restarle uno por la última vuelta del bucle

	// Hacemos el cambio de la x por la cola del coche
	b.board[i][j] = car; // Ponemos el caracter del coche en el hueco de la X
	b.board[i][j+size] = 'X'; // Ponemos la X en su nueva posición
	updateXCoords(b, i, j+size); // Actualizamos la posición de la X
	if (car == 'Z'){
		updateZCoords(b, i, j); // Actualizamos la posición de la Z
	}

	return car;
}

