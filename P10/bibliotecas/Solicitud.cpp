#include "Solicitud.h"
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <random>

std::mt19937_64
	seed(std::chrono::steady_clock::now().time_since_epoch().count());
int random(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed);
}

char* Solicitud::doOperation(char* direccion, int puerto, Mensaje::allowedOperations operation, char *arguments, size_t len, size_t & len_reply) {
	Mensaje *men = new Mensaje();
	men->messageType = Mensaje::kindMessages::request;
	men->requestId = random(1, 1 << 30);
	men->operationId = operation;
	memcpy(men->arguments, arguments, len);
	men->length = len;

	PaqueteDatagrama paquete((char*)men, sizeof(Mensaje), direccion, puerto);
	SocketDatagrama s;
	s.envia(paquete);

	Mensaje *men2 = new Mensaje();
	PaqueteDatagrama paqueteres((char*)men2, sizeof(Mensaje));
	s.recibe(paqueteres);
	len_reply = men2->length;
	return men2->arguments;
}

Solicitud::Solicitud() {}
