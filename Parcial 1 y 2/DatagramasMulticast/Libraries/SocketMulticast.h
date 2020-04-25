#include "DatagramPacket.h"
#include <cstddef>
#include <string>
#include <netinet/in.h>
#include <errno.h>

#ifndef SOCKET_MULTICAST_H_
#define SOCKET_MULTICAST_H_
class SocketMulticast{
	public:
		SocketMulticast();
	 	SocketMulticast(uint16_t iport);
	 	SocketMulticast(uint16_t iport, const std::string &);
	 	~SocketMulticast();
	 	void unbind();

	 	int send(DatagramPacket &p, unsigned char ttl);
		int receive(DatagramPacket &p);
		int receiveTimeout(DatagramPacket & p, time_t seconds, suseconds_t microseconds);
	 	//Se une a un grupo multicast, recibe la IP multicast
	 	void joinGroup(char *);
	 	//Se sale de un grupo multicast, recibe la IP multicast
 		void leaveGroup(char *);

	private:
 		int s; //ID socket
		struct sockaddr_in localAddress;
		struct sockaddr_in remoteAddress;
		struct timeval timeout;
};
#endif