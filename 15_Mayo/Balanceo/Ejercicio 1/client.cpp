#include <iostream>
#include <string>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector> 
#include <thread>
#include "Request.h"

using namespace std;

char BUFFER[34];
vector <string> IPs;
vector <uint16_t> PORTs;
Request REQUESTs[3];

void Send(string ip, uint16_t port, string BUFFER, int rqN){
	size_t len_response;
	REQUESTs[rqN].doOperation(ip, (uint16_t) port, Menssage::allowedOperations::send, (char*)BUFFER.c_str(), TAM_MAX_DATA, len_response);
}

int main(int argc, char* argv[]) {
	for(int i = 1; i <= 3; i++){
		IPs.push_back(argv[i * 2]);
		PORTs.push_back(atoi(argv[i * 2 + 1]));
	}
	int origin, bytesRead, n = 0, numreg = 0, serverElec;

	if((origin = open("diezmil", O_RDONLY)) < 0){
		//cerr << "ERROR: Open register file" << endl;
		exit(-1);
	}


	numreg = atoi(argv[1]);
	while ((bytesRead = read(origin, BUFFER, 34)) > 0 && n < numreg){
		serverElec = ((int) BUFFER[9]) - '0';
		cout << serverElec << endl;
		if(serverElec <= 3){
			//Send(IPs[0], PORTs[0], string(BUFFER), REQUESTs[0]);
			thread t(Send, IPs[0], PORTs[0], string(BUFFER), 0);
			t.detach();
		}else if(serverElec <= 6){
			//Send(IPs[1], PORTs[1], string(BUFFER), REQUESTs[1]);
			thread t(Send, IPs[1], PORTs[1], string(BUFFER), 1);
			t.detach();
		}else{
			//Send(IPs[2], PORTs[2], string(BUFFER), REQUESTs[2]);
			thread t(Send, IPs[2], PORTs[2], string(BUFFER), 2);
			t.detach();
		}
		n++;
		usleep(1000);
		//cout <<"Respuesta Servidor Timestamp:" <<respues_ser<< endl;
	}
	close(origin);
	return 0;
}
