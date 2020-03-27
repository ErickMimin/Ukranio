#include "SocketDatagrama.h"
#include "mensaje.h"
#include <stdlib.h>
#include <string.h>

#ifndef SOLICITUD_H
#define SOLICITUD_H

class Solicitud{
    public:
    	Solicitud();
    	char* doOperation(char* direccion, int puerto, Mensaje::allowedOperations operation, char *arguments, size_t len, size_t & len_reply);
    private:
    	SocketDatagrama *socketlocal;
};
#endif
