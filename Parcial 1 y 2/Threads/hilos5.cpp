#include <iostream>
#include <unistd.h>
#include <atomic>
#include <thread>
using namespace std;


int n=0;

/*void funcion(int valor)
{
//cout<<"Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
sleep(2);
}*/

void incrementaValor(atomic<int> & varLocal){
	for(int i=0; i<n; i++){
		varLocal++;
		usleep(100);
	}
}

void decrementaValor(atomic<int> & varLocal){
	for(int i=0; i<n; i++){
		varLocal--;
		usleep(100);
	}
}

int main()
{
	atomic<int> varLocal(0);
	cin >> n;

	thread th1(incrementaValor, ref(varLocal)), th2(decrementaValor, ref(varLocal));
	//printf( "Id del Hilo: %ld Valor recibido %d", this_thread::get_id(), valor)
	cout << "Proceso principal espera que los hilos terminen\n";
	th1.join();
	th2.join();
	cout << "Valor de la variable global:" << varLocal << endl;
	exit(0);
}
