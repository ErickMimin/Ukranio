run_cli: Client
	./Client 239.5.5.1 3000 1 5

run_ser: Server
	./Server 239.5.5.1 3000 1

DatagramPacket.o: ../Libraries/DatagramPacket.cpp ../Libraries/DatagramPacket.h
	g++ -c ../Libraries/DatagramPacket.cpp

SocketMulticast.o: ../Libraries/SocketMulticast.cpp ../Libraries/SocketMulticast.h
	g++ -c ../Libraries/SocketMulticast.cpp

Client: DatagramPacket.o SocketMulticast.o Client.cpp
	g++ DatagramPacket.o SocketMulticast.o Client.cpp -o Client -I../Libraries

Server: DatagramPacket.o SocketMulticast.o Server.cpp
	g++ DatagramPacket.o SocketMulticast.o Server.cpp -o Server -I../Libraries

clean:
	rm -rf *.o Client Server