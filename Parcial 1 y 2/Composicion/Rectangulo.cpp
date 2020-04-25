#include "Rectangulo.h"

Rectangulo::Rectangulo(): superiorIzq(0,0), inferiorDer(0,0){}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer){}

Rectangulo::Rectangulo(Coordenada superiorIzq, Coordenada inferiorDer): superiorIzq(superiorIzq), inferiorDer(inferiorDer){}

void Rectangulo::imprimeEsq(){
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

void Rectangulo::imprimeArea(){
    double alto, ancho;
    alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    cout << "El área del rectángulo es = " << alto * ancho << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}
