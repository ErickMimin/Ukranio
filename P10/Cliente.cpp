#include "Solicitud.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	char* ip;
	int puerto;
	int num[2];
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Numeros a sumar: ";
	cin >> num[0] >> num[1];

	Solicitud r;
	size_t len_reply;
	int *suma = (int*)r.doOperation(ip, puerto, Mensaje::allowedOperations::sum, (char*)num, sizeof(num), len_reply);
	
	cout << "Respuesta desde el servidor con longitud " << len_reply << ": " << *suma << "\n";
	
	return 0;
}
