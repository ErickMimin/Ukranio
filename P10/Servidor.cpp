#include <iostream>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	Respuesta r(uint16_t atoi(arg[2]));
	cout << "Servidor iniciado...\n";
	while(1){
		Mensaje *men = r.getRequest();
		int* nums = (int*)men->arguments;
		cout << "Solicitud enviada desde el cliente " << r.Direccion << ":" << r.puerto << "\n";
		cout << " requestId=" << men->requestId << "\n";
		cout << " operationId=" << men->operationId << "\n";
		cout << " sizeof(args)=" << men->length << "\n";
		if (men->operationId == Mensaje::allowedOperations::sum) {
			cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
			int suma = nums[0] + nums[1];
			r.sendReply((char*)&suma,sizeof(suma));
		}
		cout << "\n";
	}
	return 0;
}
