#include "Solicitud.h"
#include <iostream>
#include <string.h>
#include <new>

using namespace std;

int main(int argc, char* argv[]){
	int num[2];
	
	/*Se guardan los datos ingresados en la línea de comandos en los números a enviar*/
	num[0]= atoi(argv[3]);
	num[1]= atoi(argv[4]);

	Solicitud r;
	size_t len_reply;
	int *suma = (int*)r.doOperation(argv[1],(uint16_t) atoi(argv[2]), Mensaje::allowedOperations::sum, (char*)num, sizeof(num), len_reply);
	
	cout << "Respuesta desde el servidor con longitud " << len_reply << ": " << *suma << "\n";
	
	return 0;
}
