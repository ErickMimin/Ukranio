#include "Respuesta.h"
#include <string.h>

Respuesta::Respuesta(int iport){
	socketlocal = new SocketDatagrama(iport);
}

Mensaje* Respuesta::getRequest() {
	Mensaje *men = new Mensaje();
	PaqueteDatagrama paquete((char*)men, sizeof(Mensaje));
	socketlocal->recibe(paquete);

	Direccion = paquete.obtieneDireccion();
	puerto = paquete.obtienePuerto();
	operation = men->operationId;
	idRespuesta = men->requestId;

	return men;
}

void Respuesta::sendReply(const char *respuesta, size_t tam) {
	Mensaje *men = new Mensaje();
	men->messageType = Mensaje::kindMessages::reply;
	men->operationId = operation;
	men->requestId = idRespuesta;
	memcpy(men->arguments, respuesta, tam);
	men->length = tam;

	PaqueteDatagrama paquete((char*)men, sizeof(Mensaje), Direccion, puerto);
	socketlocal->envia(paquete);
}
