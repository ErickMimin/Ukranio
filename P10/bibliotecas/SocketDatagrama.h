#ifndef SOCKET_DATAGRAMA_H_
#define SOCKET_DATAGRAMA_H_
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

class SocketDatagrama{
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		SocketDatagrama();
		
		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama & p);

		//Env�a un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama & p);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket
};
#endif