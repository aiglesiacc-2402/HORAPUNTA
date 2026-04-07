#include "Board.h"
#include "Resolver.h"
#include "HillClimbing.h"

using namespace std;
const string file = "HORAPUNTA6.txt";

int main(){
    Board b;
    loadBoard(b, file);
	tree.insert(b);
    showBoard(b);
	cout<<endl << "ahora resolvemos" << endl;
	//prueba();
	resolve();
    SimpleHillClimbing(b);
    SteepestAscentHillClimbing(b);
    return 0;
}
