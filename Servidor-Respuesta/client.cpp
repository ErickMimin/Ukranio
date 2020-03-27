#include <iostream>
#include <string>
#include "Request.h"

using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	int nums[2];

    /* Guardamos numeros en el arreglo */
    nums[0] = atoi(argv[3]);
    nums[1] = atoi(argv[4]);

	Request r;
	size_t len_reply;
	int *suma = (int*)r.doOperation(argv[1], (uint16_t) atoi(argv[2]), Menssage::allowedOperations::sum, (char*)nums, sizeof(nums), len_reply);
	
	cout << "El resultado de la suma es " << "(longitud = " << len_reply << "): " << *suma << endl;;
	
	return 0;
}
