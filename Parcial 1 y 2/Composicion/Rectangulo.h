#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include <iostream>
#include "Coordenada.h"
using namespace std;

class Rectangulo{
    private:
        Coordenada superiorIzq;
        Coordenada inferiorDer;
    public:
        Rectangulo();
        Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
        Rectangulo(Coordenada, Coordenada);
        void imprimeEsq();
        void imprimeArea();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
};
#endif