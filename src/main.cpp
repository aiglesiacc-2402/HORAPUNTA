#include "Board.h"
#include "Resolver.h"
#include "HillClimbing.h"

using namespace std;
const string file = "HORAPUNTA6.txt";

int main(){
    int respuesta = -1;
    cout << "-----------------" << endl;
    cout << "--- HORAPUNTA ---" << endl;
    cout << "-----------------" << endl;
    cout << "Seleccione: " << endl;
    cout << "[0] Escalada simple" << endl;
    cout << "[1] Maxima pendiente" << endl;
    cout << "[2] El primer mejor" <<endl;
    bool flag = false;
    while(!flag){
        cout << "Respuesta: ";
        cin >> respuesta;
        if(respuesta < 0 || respuesta > 2){
            cout << "Respuesta no valida" <<endl;
        }
        else flag = true;
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
    default:
        break;
    }
    return 0;
}
