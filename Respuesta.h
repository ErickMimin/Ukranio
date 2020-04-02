#include "SocketDatagrama.h"
#include "mensaje.h"

#ifndef RESPUESTA_H
#define RESPUESTA_H

class Respuesta{
	public:
		Respuesta(int pl);
		struct mensaje *getRequest(void);
		void sendReply(char *respuesta);
	private:
		SocketDatagrama *socketlocal;
};
#endif
