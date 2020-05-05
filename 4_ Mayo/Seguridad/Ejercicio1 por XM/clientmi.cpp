#include <iostream>
#include <string>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector> 
#include "Request.h"


using namespace std;

char BUFFER[34];

int main(int argc, char* argv[]) {
	string ip = "127.0.0.1";
	uint16_t puerto = 3000;
	size_t len_response;
	Request r;
	Registro regis;
	vector<Registro> registros_vector; 
	int origin, *result;

	if((origin = open("setemil", O_RDONLY)) < 0){
		cerr << "ERROR: Open register file" << endl;
		exit(-1);
	}


	int bytesRead,n=1,numreg=0;
	numreg=atoi(argv[1]);
	while ((bytesRead = read(origin, BUFFER, sizeof(BUFFER))) > 0 & n < numreg){
		memcpy((char*)&regis, BUFFER, bytesRead);
		registros_vector.push_back(regis);
		result = (int*)r.doOperation(ip, (uint16_t) puerto, Menssage::allowedOperations::send, (char*)&regis, TAM_MAX_DATA, len_response);
		n++;
	}

	for (std::vector<Registro>::iterator it=registros_vector.begin(); it!=registros_vector.end(); ++it){
		regis = *it;
		cout << regis.celular << endl;
		cout << regis.CURP << endl;
		cout << regis.partido << endl;

	}

	result = (int*)r.doOperation(ip, (uint16_t) puerto, Menssage::allowedOperations::send, (char*)&regis, TAM_MAX_DATA, len_response);
	cout << *result << endl;
	close(origin);
	return 0;
}
