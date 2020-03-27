#include "SocketDatagrama.h"
#include "mensaje.h"

#ifndef RESPUESTA_H
#define RESPUESTA_H

class Respuesta{
	public:
		Respuesta(int pl);
		struct Mensaje *getRequest(void);
		char *Direccion;
		int puerto;
		unsigned int idRespuesta;
		void sendReply(const char *respuesta, size_t tam);
	private:
		SocketDatagrama *socketlocal;
		Mensaje::allowedOperations operation;
};
#endif
