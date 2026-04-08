#include "Board.h"
#include "Resolver.h"
#include "HillClimbing.h"

using namespace std;
string base = "HORAPUNTA";
string file;

int main(){
    int respuesta = -1;
    cout << "-----------------" << endl;
    cout << "--- HORAPUNTA ---" << endl;
    cout << "-----------------" << endl;
    cout << "Seleccione el ALGORITMO DE RESOLUCION: " << endl;
    cout << "[0] Escalada simple" << endl;
    cout << "[1] Maxima pendiente" << endl;
    cout << "[2] El primero mejor" <<endl;
    cout << "[3] A*" << endl;
    cout << "[4] Algoritmo de enfriamiento" << endl;

    bool flag = false;
    while(!flag){
        cout << "Respuesta: ";
        cin >> respuesta;
        if(respuesta < 0 || respuesta > 4){
            cout << "Respuesta no valida" <<endl;
        }
        else flag = true;
    }

    int tablero = -1;
    cout << "-----------------" << endl;
    cout << "--- HORAPUNTA ---" << endl;
    cout << "-----------------" << endl;
    cout << "Seleccione el TABLERO a resolver [1,10]: " << endl;
    flag = false;
    while(!flag){
        cout << "Tablero: ";
        cin >> tablero;
        if(tablero < 1 || tablero > 10){
            cout << "Tablero no existente" <<endl;
        }
        else{
            file = base + to_string(tablero) + ".txt"; //Esta línea cambia el numero del tablero a cargar accediendo a la posición del número
            flag = true;
        }
    }
    

    Board b;
    loadBoard(b, file);
    showBoard(b);
    switch (respuesta)
    {
    case 0:
        cout << "Resolviendo con escalada simple" << endl;
        SimpleHillClimbing(b);
        break;
    
    case 1:
        cout << "Resolviendo con maxima pendiente" << endl;
        SteepestAscentHillClimbing(b);
        break;

    case 2:
        cout << "Resolviendo con primero mejor" << endl;
        tree.insert(b);
        resolve();
        break;
    case 3:
        cout << "Resolviendo con A*" << endl;
        tree.insert(b);
        resolveAStar();
        break;

    case 4:
        cout << "Resolviendo con Algortimo de enfriamiento" << endl;
        SimulatedAnnealing(b);
        break;
    default:
        break;
    }
    return 0;
}
