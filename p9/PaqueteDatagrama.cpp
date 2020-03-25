#include "PaqueteDatagrama.h"

//Constructor que crea un paquete de envío tipo datagrama. 
PaqueteDatagrama::PaqueteDatagrama(char *data, unsigned int tam, char * dirIP, int pto){
	datos= new char[longitud]; //Datos a enviarse con memoria dinámica
	longitud=tam; //Tamaño de los datos
	puerto=pto; //Puerto
	memcpy(datos, data, longitud); //Copia la información en los datos para enviarse
	memcpy(ip,dirIP,sizeof(ip)); //Copia la dirección IP a enviar en IP
}

//Constructor que crea un paquete de envío vacío.
PaqueteDatagrama::PaqueteDatagrama(unsigned int tamanio){
	longitud=tamanio;
	datos= new char[longitud];
}

//Deconstructor
PaqueteDatagrama::~PaqueteDatagrama(){
	delete(datos); //Libera el espacio de memoria en datos
}

//Retorna la dirección ip 
char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

//Retorna la longitud o tamaño de los datos
unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

//Retorna el puerto
int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

//Retorna los datos a enviar
char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

//Inicializa el puerto
void PaqueteDatagrama::inicializaPuerto(int pto){
	puerto=pto;
}

//Inicializa la dirección IP
void PaqueteDatagrama::inicializaIp(char * dirIP){
	memcpy(ip,dirIP,INET_ADDRSTRLEN); 
}

//Inicializamos los datos a enviar
void PaqueteDatagrama::inicializaDatos(char * data){
	memcpy(datos,data,longitud); 	
}
