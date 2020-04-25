#ifndef POLIGONO_H_
#define POLIGONO_H_
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "Coordenada.h"
using namespace std;

class Poligono{
    private:
        vector<Coordenada> coordenadas;
        static int vertCreados;
    public:
        Poligono();
        void addVertice(Coordenada);
        void addVertices(int);
        void imprimeVertices();
        static int imprimeVerticesTotales();
        static bool whoIsMax(Coordenada, Coordenada);
        void ordenaA();
};
#endif