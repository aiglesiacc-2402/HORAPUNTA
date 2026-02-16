#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

char board[6][6];
const string file = "HORAPUNTA1.txt";

void showBoard(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			cout << board[i][j]<<" ";
		}
		cout<<endl;
	}
}

pair<int,int> buscarX(char board[6][6]){
	int x,y;
for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
			    if(board[i][j] == 'X'){
                     x = i;
					 y = j;
				}
			}
		}
		pair<int,int> position = {x,y};
	return position;
}

int main(){
	ifstream finalFile;
	finalFile.open("BOARDS/" + file);
	string row;

	if(finalFile.is_open()){
		for(int i = 0; i < 6; i++){
            getline(finalFile, row);
			for(int j = 0; j < 6; j++){
			    board[i][j] = row[j*2];
			}
		}
		finalFile.close();
		showBoard();
	} else {
		cout <<"Fichero de carga no encontrado (<HORAPUNTA>/" << file << ")" <<endl;
	}

	return 0;
}
