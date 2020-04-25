#include "Poligono.h"


Poligono::Poligono(){}

int Poligono::vertCreados = 0;

void Poligono::imprimeVertices(){
    for(int i = 0; i < coordenadas.size(); i++)
        cout << "Coordenada " << i << ": " << coordenadas[i].obtenerX() << ", " << coordenadas[i].obtenerY()<< " Magnitud: " << coordenadas[i].obtenerM() << endl;
}

void Poligono::addVertice(Coordenada add){
    coordenadas.push_back(add);
    vertCreados ++;
}

void Poligono::addVertices(int m){
    int inicio = coordenadas.size();
    int final = inicio + m;
    coordenadas.resize(final);
    for(int i = inicio; i < final; i++){
        coordenadas[i] = Coordenada(((rand() % 200000) / 1000.0) - 100.0, ((rand() % 200000) / 1000.0) - 100.0);
        coordenadas[i].setMagnitud(sqrt(pow(coordenadas[i].obtenerX(), 2) + pow(coordenadas[i].obtenerY(), 2)));
    }
    vertCreados += m;
}

int Poligono::imprimeVerticesTotales(){
    return vertCreados;
}

bool Poligono::whoIsMax(Coordenada i, Coordenada j){
    return i.obtenerM() < j.obtenerM();
}

void Poligono::ordenaA(){
   sort(coordenadas.begin(), coordenadas.end(), whoIsMax); 
}