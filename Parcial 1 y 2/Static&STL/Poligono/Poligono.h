#ifndef POLIGONO_H_
#define POLIGONO_H_
#include <iostream>
#include <vector>
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
};
#endif