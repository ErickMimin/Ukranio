#include <iostream>
#include <unistd.h>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> varGlobal(0);
int n=0;

/*void funcion(int valor)
{
//cout<<"Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
sleep(2);
}*/

void incrementaValor(){
	for(int i=0; i<n; i++){
		varGlobal++;
		usleep(100);
	}
}

void decrementaValor(){
	for(int i=0; i<n; i++){
		varGlobal--;
		usleep(100);
	}
}

int main()
{
	
	cin >> n;
	thread th1(incrementaValor), th2(decrementaValor);
	//printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "Valor de la variable global:" << varGlobal << endl;
	exit(0);
}
