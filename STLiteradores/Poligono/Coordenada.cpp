#include "Coordenada.h"
#include <math.h>

Coordenada::Coordenada(double x, double y): x(x), y(y){}

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}

double Coordenada::obtenerM(){
    return magnitud;
}

void Coordenada::setMagnitud(double m){
    magnitud = m;
}
