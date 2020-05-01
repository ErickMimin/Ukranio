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
	string ip = "192.168.8.115";
	uint16_t puerto = 3000;
	size_t len_response;
	Request r;
	Registro regis;
	vector<Registro> registros_vector; 
	int origin, *result;

	if((origin = open("diezmil", O_RDONLY)) < 0){
		cerr << "ERROR: Open register file" << endl;
		exit(-1);
	}


	int bytesRead,n=0,numreg=0;
	numreg=atoi(argv[1]);
	while ((bytesRead = read(origin, BUFFER, sizeof(BUFFER))) > 0 & n < numreg){
		result = (int*)r.doOperation(ip, (uint16_t) puerto, Menssage::allowedOperations::send, (char*)&BUFFER, TAM_MAX_DATA, len_response);
		n++;
		cout <<"Respuesta Servidor:" <<*result << endl;
	}
	close(origin);
	return 0;
}
