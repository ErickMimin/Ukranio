#include "Fecha.h"
#include <iostream>
using namespace std;

int masVieja(Fecha f1, Fecha f2){
    return f1.convierte() > f2.convierte() ? 1 : (f1.convierte() == f2.convierte() ? 0 : -1);
}

int masViejaRef(Fecha& f1, Fecha& f2){
    return f1.convierte() > f2.convierte() ? 1 : (f1.convierte() == f2.convierte() ? 0 : -1);
}

int masVieja(Fecha *f1, Fecha *f2){
    return (*f1).convierte() > (*f2).convierte() ? 1 : ((*f1).convierte() == (*f2).convierte() ? 0 : -1);
}

int main(int argc, char* argv[]){
    int n = 999999;
    Fecha date1((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);
    Fecha date2((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);   
    cout << sizeof(date1) << endl;
    if(atoi(argv[1]) == 1)
        while(n--){
            masViejaRef(date1, date2);  
            date1.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
            date2.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
        }
    else if(atoi(argv[1]) == 2)
        while(n--){
            masVieja(date1, date2);
            date1.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
            date2.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
        }
    else 
        while(n--){
            masVieja(&date1, &date2);
            date1.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
            date2.inicializaFecha((rand() % 31) + 1, (rand() % 12) + 1, rand() % 2020);          
        }
}