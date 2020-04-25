#include "Coordenada.h"
#include <math.h>

Coordenada::Coordenada(double r, double tetha): x(r * cos(tetha)), y(r * sin(tetha)){}

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}