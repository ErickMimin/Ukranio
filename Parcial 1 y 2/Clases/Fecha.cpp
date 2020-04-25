#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa){
    if(dia < 1 || dia > 31){
        cout << "Dia incorrecto" << endl;
        exit(1);
    }else if(mes < 1 || mes > 12){
        cout << "Mes incorrecto" << endl;
        exit(1);
    }else if(anio < 0 || anio > 2020){
        cout << "Anio incorrecto" << endl;
        exit(1);
    }
}

void Fecha::setAnio(int aaaa){
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
    return;
}

int Fecha::convierte(){
    return anio * 10000 + mes * 100 + dia;
}

bool Fecha::leapyr(){
    return (anio % 100 && !(anio % 4)) || !(anio % 400);
}