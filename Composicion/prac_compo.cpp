#include "Rectangulo.h"
#include <math.h>

int main(){
    Rectangulo rectangulo1(Coordenada(sqrt(13.0), atan(3.0/2.0)), Coordenada(sqrt(26.0), atan(1.0/5.0)));
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un planotesiano:\n";
    rectangulo1.imprimeEsq();    
    rectangulo1.imprimeArea();
    return 0;
} 