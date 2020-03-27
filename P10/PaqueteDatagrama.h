#ifndef PAQUETE_DATAGRAMA_H_
#define PAQUETE_DATAGRAMA_H_
#include <new>
#include <cstring>
#include <stdio.h>
#include <cstring>
#include <arpa/inet.h>
using namespace std;
class PaqueteDatagrama {
	public:
		PaqueteDatagrama(char * const buf, size_t len);
		PaqueteDatagrama(char *, unsigned int, char *, int );
		PaqueteDatagrama(unsigned int);
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int);
		void inicializaIp(char *);
		void inicializaDatos(char *);
	
	private:
		char *datos;//Almacena los datos
		char ip[16];//Almacena la IP
		unsigned int longitud;//Almacena la longitude de la cadena de datos
		int puerto;//Almacena el puerto
};
#endif
