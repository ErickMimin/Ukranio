#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

int varGlobal=0;

void funcion(int valor)
{
//cout<<"Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor);
sleep(2);
}

void incrementaValor(){
	varGlobal++;
	sleep(1);
}

void decrementaValor(){
	varGlobal--;
	sleep(1);
}

int main()
{
thread th1(incrementaValor), th2(decrementaValor);
//printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
cout << "Proceso principal espera que los hilos terminen\n";
th1.join();
th2.join();
printf("Valor de la variable global: %d \n", varGlobal);
exit(0);
}
