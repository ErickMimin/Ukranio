#include "Fecha.h"

int Fecha::vecesMuestF = 0;


int Fecha::getVecesMuestF(){
    /*
    dia += 1;
    mes += 1;
    anio += 1;
    */
    return vecesMuestF;
}

Fecha::Fecha(int dd, int mm, int aaaa){
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha(){
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    vecesMuestF++;
    return;
}