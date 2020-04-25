#include "Poligono.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int n = 1, i = 0;
    srand((unsigned) time(NULL));
    vector<Poligono> poligonos(n);
    vector<Poligono>::iterator poligono;
    for(poligono = poligonos.begin(); poligono != poligonos.end(); poligono++){
        cout << "Poligno : " << ++i << endl;
        (*poligono).addVertices(7);
        (*poligono).imprimeVertices();
        cout << '\n';
        (*poligono).ordenaA();
        (*poligono).imprimeVertices();
    }
    
} 