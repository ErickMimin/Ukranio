#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Request.h"


using namespace std;

char BUFFER[34];

void copyBuffer(char* des, int ori){
	int bytesRead;
	if((bytesRead = read(ori, BUFFER, sizeof(BUFFER))) < 0){
		cerr << "ERROR: Read register" << endl;
		exit(-1);
	}
	memcpy(des, BUFFER, bytesRead);
}


int main(int argc, char* argv[]) {
	string ip = "127.0.0.1";
	uint16_t puerto = 3000;
	size_t len_response;
	Request r;
	Registro regis;
	int origin, *result;

	if((origin = open("registro", O_RDONLY)) < 0){
		cerr << "ERROR: Open register file" << endl;
		exit(-1);
	}

	copyBuffer((char*)&regis, origin);

	cout << regis.celular << endl;
	cout << regis.CURP << endl;
	cout << regis.partido << endl;

	result = (int*)r.doOperation(ip, (uint16_t) puerto, Menssage::allowedOperations::send, (char*)&regis, TAM_MAX_DATA, len_response);

	cout << *result << endl;

	close(origin);

	return 0;
}
