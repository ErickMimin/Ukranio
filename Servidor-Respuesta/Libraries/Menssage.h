#ifndef MENSSAGE_H_
#define MENSSAGE_H_
//Definicion de identificadores para operaciones permitidas
#define TAM_MAX_DATA 40000

class Menssage {
	public:
        /* Constantes */
		enum kindMessages: int {request = 0, response};
		enum allowedOperations: int {sum = 0, transfer = 1, verification = 2};

		Menssage::kindMessages messageType;    
		unsigned int requestId;
		Menssage::allowedOperations operationId;
		char arguments[TAM_MAX_DATA];
		size_t length;
};
#endif