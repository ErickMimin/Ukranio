#include "Poligono.h"


Poligono::Poligono(){}

int Poligono::vertCreados = 0;

void Poligono::imprimeVertices(){
    cout << "Imprimiendo Coordenadas" << endl;
    for(int i = 0; i < coordenadas.size(); i++)
        cout << "Coordenada " << i << ": " << coordenadas[i].obtenerX() << ", " << coordenadas[i].obtenerY() << endl;
}

void Poligono::addVertice(Coordenada add){
    coordenadas.push_back(add);
    vertCreados ++;
}

void Poligono::addVertices(int m){
    int inicio = coordenadas.size();
    int final = inicio + m;
    coordenadas.resize(final);
    for(int i = inicio; i < final; i++)
        coordenadas[i] = Coordenada(0, 0);
    vertCreados += m;
}

int Poligono::imprimeVerticesTotales(){
    return vertCreados;
}