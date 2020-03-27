#include "DatagramSocket.h"
#include <netinet/in.h>
#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

DatagramSocket::DatagramSocket(): DatagramSocket(0) {}

DatagramSocket::DatagramSocket(uint16_t iport): DatagramSocket(iport, "0.0.0.0") {}

DatagramSocket::DatagramSocket(uint16_t iport, const string &addr){
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	bzero((char *)&localAddress, sizeof(localAddress));
	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr(addr.c_str());
	localAddress.sin_port = htons(iport);
	bind(s, (struct sockaddr *)&localAddress, sizeof(localAddress));
}

DatagramSocket::~DatagramSocket(){
	unbind();
}

void DatagramSocket::unbind(){
	close(s);
	s = 0;
}

int DatagramSocket::receiveTimeout(DatagramPacket & p, time_t seconds, suseconds_t microseconds){
	timeout.tv_sec=seconds;
	timeout.tv_usec= microseconds;
	/*  SOL_SOCKET --> Nivel de conector 
		SO_RCVTIMEO --> Especifica el plazo de tiempo para recibir antes de informar de un error
					   En Linux es un valor fijo y viene dado por una configuración específica del
					   protocolo, no se puede leer ni modificar */
	setsockopt(s, SOL_SOCKET,SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
	socklen_t len = sizeof(remoteAddress);
	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);
	if(n < 0){
		if(errno== EWOULDBLOCK)
			fprintf(stderr, "Tiempo de recepción transcurrido\n");
		else
			fprintf(stderr, "Error en recvfrom\n");
		
	}
	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	
	return n;
}

int DatagramSocket::receive(DatagramPacket &p){
	socklen_t len = sizeof(remoteAddress);
	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);
	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	return n;
}

int DatagramSocket::send(DatagramPacket &p){
	bzero((char *)&remoteAddress, sizeof(remoteAddress));
	remoteAddress.sin_family = AF_INET;
	remoteAddress.sin_port = htons(p.getPort());
	remoteAddress.sin_addr.s_addr = inet_addr(p.getAddress().c_str());
	return sendto(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, sizeof(remoteAddress));
}
