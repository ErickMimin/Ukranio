#include "SocketMulticast.h"
#include "DatagramPacket.h"
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
SocketMulticast::SocketMulticast(): SocketMulticast(0) {}


SocketMulticast::~SocketMulticast(){
	unbind();
}

void SocketMulticast::unbind(){
	close(s);
	s = 0;
}

SocketMulticast::SocketMulticast(uint16_t iport): SocketMulticast(iport, "0.0.0.0") {}

SocketMulticast::SocketMulticast(uint16_t iport, const std::string &addr){
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		throw "ERROR: Could not create socket " + std::string(strerror(errno));
	bzero((char *)&localAddress, sizeof(localAddress));
	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr(addr.c_str());
	localAddress.sin_port = htons(iport);
	int reuse = 1;
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
		throw "ERROR: Could not set reuse port";
	if(addr != "0.0.0.0" || iport != 0)
		if (bind(s, (struct sockaddr *)&localAddress, sizeof(localAddress)) < 0)
			throw "ERROR: Could not bind: " + std::string(strerror(errno));
}

void SocketMulticast::joinGroup(char *IP){
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

void SocketMulticast::leaveGroup(char *IP){
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

int SocketMulticast::send(DatagramPacket &p, unsigned char TTL){
	bzero((char *)&remoteAddress, sizeof(remoteAddress));
    remoteAddress.sin_family = PF_INET;
    remoteAddress.sin_addr.s_addr = inet_addr(p.getAddress().c_str());
    remoteAddress.sin_port = htons(p.getPort());
    if(setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL)) < 0)
		throw "ERROR: Could not set TTL paramater";
	return sendto(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, sizeof(remoteAddress));
}

int SocketMulticast::receive(DatagramPacket &p){
    //bzero((char *)&remoteAddress, sizeof(remoteAddress));//inicializa en null
    socklen_t len = sizeof(remoteAddress);
	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);
    //inet_ntop(AF_INET, &(remoteAddress.sin_addr.s_addr), (string(inet_ntoa(remoteAddress.sin_addr))).c_str(), INET_ADDRSTRLEN);//IP?
	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(std::string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	return n;
}

int SocketMulticast::receiveTimeout(DatagramPacket &p, time_t seconds, suseconds_t microseconds){
	timeout.tv_sec = seconds;
	timeout.tv_usec = microseconds;	
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

	socklen_t len = sizeof(remoteAddress);

	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);

	if (n < 0) {
		if (errno == EWOULDBLOCK)
			throw "ERROR: Timeout while receiving the packet";
		else
			throw "ERROR: While receiving the packet";
	}

	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(std::string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	return n;
}

int SocketMulticast::reliableSend(DatagramPacket & p, unsigned char ttl, int num_receptores){
	int receptores_recibidos = 0; 
	send(p, ttl);

	int ack[1];
	DatagramPacket paqAcuse = DatagramPacket((char*)ack, sizeof(int));

	while(receptores_recibidos < num_receptores){
		if(receiveTimeout(paqAcuse, 3,0) < 0){
			unbind();
			std::cout << "Recibo de acuse no recibido"<< std::endl;
			return -1;
		}
		receptores_recibidos++;
		std::cout << "Acuse #" << receptores_recibidos << " de " << paqAcuse.getAddress() << std::endl;
	}
	return receptores_recibidos;
}

int SocketMulticast::realiableReceive(DatagramPacket &p, unsigned char ttl){
	int ans = receive(p);
	char res = 1;
	DatagramPacket dp(&res, 1, p.getAddress(), p.getPort());
	send(dp, ttl);
	return ans;
}