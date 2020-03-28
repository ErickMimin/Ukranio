#include "PaqueteDatagrama.h"
<<<<<<< HEAD
#include<new>
#include<string>
=======
#include <new>
#include <cstring>
#include <stdio.h>
#include <cstring>
#include <arpa/inet.h>
>>>>>>> 82608b108d1479837cf5a10a86eddee111f13a67

//Constructor que crea un paquete de envio tipo datagrama.
PaqueteDatagrama::PaqueteDatagrama(char* const data, size_t tam)	{	
	datos= new char[longitud]; //Datos a enviarse con memoria dinamica
	longitud=tam; //Tamaño de los datos
	memcpy(datos, data, longitud); //Copia la informacion en los datos para enviarse
}

//Constructor que crea un paquete de envio tipo datagrama.
PaqueteDatagrama::PaqueteDatagrama(char *data, unsigned int tam, char * dirIP, int pto)	{	
	datos= new char[longitud]; //Datos a enviarse con memoria dinamica
	longitud=tam; //Tamaño de los datos
	puerto=pto; //Puerto
	memcpy(datos, data, longitud); //Copia la informacion en los datos para enviarse
	memcpy(ip,dirIP,sizeof(ip)); //Copia la direccion IP a enviar en IP
}

//Constructor que crea un paquete de envio vacio.
PaqueteDatagrama::PaqueteDatagrama(unsigned int tamanio){
	longitud=tamanio;
	datos= new char[longitud];
}

//Deconstructor
PaqueteDatagrama::~PaqueteDatagrama(){
	delete(datos); //Libera el espacio de memoria en datos
}

//Retorna la direccion ip
char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

//Retorna la longitud o tama�o de los datos
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

//Inicializa la direccion IP
void PaqueteDatagrama::inicializaIp(char * dirIP){
	memcpy(ip,dirIP,INET_ADDRSTRLEN);
}

//Inicializamos los datos a enviar
void PaqueteDatagrama::inicializaDatos(char * data){
	memcpy(datos,data,longitud);
}
