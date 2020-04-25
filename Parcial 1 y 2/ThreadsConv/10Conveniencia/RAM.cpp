#include <iostream>
#include <cstdlib>

using namespace std;

#define numeroElementos 999000000

int main() {
	unsigned long *arreglo, i;
	arreglo = new unsigned long[numeroElementos];
	for(i = 0; i < numeroElementos; i++)
		arreglo[i] = 0;
	for(i = 0; i < 1000010000; i++){
		arreglo[rand() % numeroElementos] = rand();
	}
}