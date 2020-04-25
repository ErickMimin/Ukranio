#ifndef MENSAJE_H
#define MENSAJE_H
#define TAM_MAX_DATA 4000
//Definicion de identificadores para operaciones permitidas
//#define suma 1
// Definicion del formato de mensaje
struct Mensaje {
	enum kindMessages: int {request = 0, reply};
	enum allowedOperations: int {sum = 0};

	Mensaje::kindMessages messageType;   //0= Solicitud, 1 = Respuesta  
	Mensaje::allowedOperations operationId;	//Identificador de la operación
	unsigned int requestId;	//Identificador del mensaje
	char arguments[TAM_MAX_DATA];
	size_t length;	
};
#endif
