#include "SocketDatagrama.h"

//Constructor que crea un socket de tuoi datagrama
SocketDatagrama::SocketDatagrama(int pto){
	s= socket(AF_INET, SOCK_DGRAM, 0); //Creamos el socket de tipo datagrama con dominio de Internet
	bzero((char *)&direccionLocal, sizeof(direccionLocal)); //Rellenamos con 0 el socket
	direccionLocal.sin_family= AF_INET; //Familia de direccion
	direccionLocal.sin_addr.s_addr= INADDR_ANY; //Poner la direccion IP del servidor automoticamente
	direccionLocal.sin_port= htons(pto); //Se decide el puerto, si es 0 entonces se asignar� autom�ticamente
	bind(s,(struct sockaddr *)&direccionLocal, sizeof(direccionLocal)); //asocia un socket a un puerto local
}

SocketDatagrama::~SocketDatagrama(){
	close(s); //Cerramos la conexion de nuestro socket
}
int SocketDatagrama::recibe(PaqueteDatagrama &p){
	char datos[p.obtieneLongitud()]; //Creamos una cadena con la longitud de los datos
	char dire[INET_ADDRSTRLEN]; //Cadena auxilar para los datos direccion IP
	socklen_t clilen = sizeof(direccionForanea); //Variable que almacena la longitud de la direcci�n foranea
	int res=recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &clilen);

	/*S --> Descriptor del socket por el cual se leen los datos,
	datos --> Buffer donde se almacena la informaci�n,
	p.obtieneLongitud() --> Longitud de los datos en el paqueteDatagrama,
	0 --> bandera,
	(struct sockaddr *) &direccionForanea --> Apuntador a la estructura de tipo sockaddr,
	&clilen(direccionForanea) --> Apuntador a un entero local*/
	inet_ntop(AF_INET, &(direccionForanea.sin_addr), dire, INET_ADDRSTRLEN);//Convertimos la direcci�n en una cadena adecuada para su lectura
	p.inicializaPuerto(ntohs(direccionForanea.sin_port)); //Iniciamos el puerto
	p.inicializaIp(dire); //Inicializamos la direcci�n IP
	p.inicializaDatos(datos); //Inicializamos los datos
return res;
}

int SocketDatagrama::envia(PaqueteDatagrama & p){
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}