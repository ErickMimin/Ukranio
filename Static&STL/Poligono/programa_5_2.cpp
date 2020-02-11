#include "Poligono.h"
#include <math.h>

int main(int argc, char* argv[]){
    int polis = 999999;
    int i, j, m;
    vector<Poligono> poligonos(polis);
    if(atoi(argv[1]) == 1)
        for(i = 0; i < polis; i++)
            poligonos[i].addVertices(rand() % 100);
    else 
        for(i = 0; i < polis; i++){
            m = rand() % 100;
            for(j = 0; j < m; j++)
                poligonos[i].addVertice(Coordenada(0, 0));
        }
    cout << "Vertices creados: " << poligonos[0].imprimeVerticesTotales() << endl;

    return 0;
} 