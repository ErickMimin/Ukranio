#include "SocketDatagrama.h"

 int main(int argc, char const *argv[]) {
 	//Conexion del cliente
 	SocketDatagrama cliente(7777); //Creamos un objeto cliente de tipo Socket Datagram
 	int num[2], res;
 	num[0]=2;
 	num[1]=5;
 	PaqueteDatagrama pack((char *)num, 2*sizeof(int), (char *) argv[1], 7200);
 	printf("%s\n","Enviado a:" );
 	printf("Direccion: %s Puerto:%d\n", pack.obtieneDireccion(), pack.obtienePuerto());
 	cliente.envia(pack);
 	printf("%s\n", "Caso exitoso, se han enviado los numeros");
 	PaqueteDatagrama packResultado(sizeof(int));
 	cliente.recibe(packResultado);
 	printf("%s\n","Recibido de:" );
 	printf("Direccion: %s\n Puerto: %d\n", packResultado.obtieneDireccion(),packResultado.obtienePuerto());
 	memcpy(&res, packResultado.obtieneDatos(), sizeof(int));
 	printf("2 + 5 = %d\n", res);
 	printf("%s\n", "En hora buena, ya tenemos el resultado");
 	return 0;
}