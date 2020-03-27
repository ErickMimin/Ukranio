all: cliente servidor

PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ -c PaqueteDatagrama.cpp -Wall

SocketDatagrama.o: SocketDatagrama.cpp
	g++ -c SocketDatagrama.cpp -Wall

Solicitud.o: Solicitud.cpp
	g++ -c Solicitud.cpp -Wall

Respuesta.o: Respuesta.cpp
	g++ -c Respuesta.cpp -Wall

cliente: PaqueteDatagrama.o SocketDatagrama.o Solicitud.o Respuesta.o
	g++ PaqueteDatagrama.o SocketDatagrama.o Solicitud.o Respuesta.o Cliente.cpp -o cliente

servidor: PaqueteDatagrama.o SocketDatagrama.o Solicitud.o Respuesta.o
	g++ PaqueteDatagrama.o SocketDatagrama.o Solicitud.o Respuesta.o Servidor.cpp -o servidor
