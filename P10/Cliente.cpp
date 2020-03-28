#include "Solicitud.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	char* ip;
	int puerto;
	int num[2];
	if(argc != 2 ){
		printf("Te han hecho falta datos en la línea de comandos\n");
	}
	/*Se guardan los datos ingresados en la línea de comandos en los números a enviar*/
	num[0]= argv[3];
	num[1]= argv[4];

	Solicitud r;
	size_t len_reply;
	int *suma = (int*)r.doOperation(argv[1],(uint16_t) argv[2], Mensaje::allowedOperations::sum, (char*)num, sizeof(num), len_reply);
	
	cout << "Respuesta desde el servidor con longitud " << len_reply << ": " << *suma << "\n";
	
	return 0;
}
