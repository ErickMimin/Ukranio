run: servidor cliente
	
servidor: servidor.o PaqueteDatagrama.o SocketDatagrama.o
	g++ SocketDatagrama.o PaqueteDatagrama.o servidor.o -o servidor
cliente: cliente.o PaqueteDatagrama.o SocketDatagrama.o 
	g++ SocketDatagrama.o PaqueteDatagrama.o cliente.o -o cliente
servidor.o: servidor.cpp
	g++ servidor.cpp -c 
cliente.o: cliente.cpp
	g++ cliente.cpp -c 
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c
SocketDatagrama.o:SocketDatagrama.cpp 
	g++ SocketDatagrama.cpp -c
clean:
	rm *.o *.out ./cliente ./servidor