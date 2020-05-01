#ifndef MENSSAGE_H_
#define MENSSAGE_H_
//Definicion de identificadores para operaciones permitidas

typedef struct {
	char celular[11];
	char CURP[19];
	char partido[4];
} Registro;

#define TAM_MAX_DATA sizeof(Registro)

class Menssage {
	public:
        /* Constantes */
		enum kindMessages: int {request = 0, response};
		enum allowedOperations: int {send = 0, verification = 1};

		Menssage::kindMessages messageType;    
		unsigned int requestId;
		Menssage::allowedOperations operationId;
		char arguments[TAM_MAX_DATA];
		size_t length;
};
#endif