#include <iostream>
#include <string>
#include "Request.h"

using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	int n= atoi(argv[3]);

    /* Guardamos numeros en el arreglo 
    nums[0] = atoi(argv[3]);
    nums[1] = atoi(argv[4]);
	*/
	do{
	Request r;
	size_t len_reply;
	//enviar al servidor el ID
	int *suma = (int*)r.doOperation(argv[1], (uint16_t) atoi(argv[2]), Menssage::allowedOperations::sum, (char*)nums, sizeof(nums), len_reply);
	
	cout << "El resultado de la suma es " << "(longitud = " << len_reply << "): " << *suma << endl;;
	n--;
	}while(n>0);
	
	
	return 0;
}
