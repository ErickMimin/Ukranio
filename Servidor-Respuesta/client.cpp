#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "Request.h"

using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	size_t len_response;
	Request r;
	int n= atoi(argv[3]);
	int *balance, *currentBalance, deposit;

	currentBalance = (int*)r.doOperation(argv[1], (uint16_t) atoi(argv[2]), Menssage::allowedOperations::verification, NULL, 0, len_response);
	cout << "Su saldo inicial es" << "(longitud = " << len_response << "): " << *currentBalance << endl;

	while(n--){
		try{
			//enviar al servidor el ID
			
			deposit = random(1, 9);
			*currentBalance += deposit;
			balance = (int*)r.doOperation(argv[1], (uint16_t) atoi(argv[2]), Menssage::allowedOperations::transfer, (char*)&deposit, sizeof(deposit), len_response);
			cout << "Su saldo actual es" << "(longitud = " << len_response << "): " << *balance << endl;

			if(*currentBalance != *balance){
				throw "Saldo inconsistente";
			}
		}catch(const char *msg) {
			cerr << msg << endl;
			return 1;
    	}
		
	};
	
	balance = (int*)r.doOperation(argv[1], (uint16_t) atoi(argv[2]), Menssage::allowedOperations::verification, NULL, 0, len_response);
	cout << "Su saldo final es" << "(longitud = " << len_response << "): " << *balance << endl;

	return 0;
}
