#include <iostream>
#include <unistd.h>
#include <vector>
#include <thread>
#include "Semaforo.h"
#define n 10
using namespace std;

int varGlobal=0;
int n=3;
vector<Semaforo> semaforos(n);
vector<thread> hilos;
mutex mux;

void funcion(int valor)
{
while(varGlobal>0){
	semaforos[hilos].wait();
	if(varGlobal>=0){
//cout<<"Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf( "Id del Hilo: %ld Valor recibido %d",  valor, varGlobal--);
	semaforos[(hilos+1)%n].post();
	}
sleep(2);
}

/*void incrementaValor(){
	for(int i=0; i<n; ++i){
		mux.lock();
		varGlobal++;
		usleep(100);
		mux.unlock();
	}
}

void decrementaValor(){
	for(int i=0; i<n; ++i){
		mux.lock();
		varGlobal--;
		usleep(100);
		mux.unlock();
	}
}*/

int main()
{
	for(int i=0; i< n; ++i){
		if(i==0) 
			semaforos[i].init(1)
		else
			semaforos[i].init(0);
	}

	for(int i=0; i< n; ++i){
		hilos.emplace_back(funcion,i);
	}

	for(auto & hilo: hilos){
		hilo.join();
	}
	
	/*cin >> n;
	thread th1(incrementaValor), th2(decrementaValor);
	//printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	printf("Valor de la variable global: %d\n", varGlobal);*/
	exit(0);
}
