run_emt: Emitter
	./Emitter 239.5.5.0 3000 1 "Hola, como estas"

run_rec: Receiver
	./Receiver 239.5.5.0 3000

run_emt_2: Emitter2
	./Emitter2 239.5.5.0 3000 1 2 4

run_rec_2: Receiver2
	./Receiver2 239.5.5.0 3000

DatagramPacket.o: ../Libraries/DatagramPacket.cpp ../Libraries/DatagramPacket.h
	g++ -c ../Libraries/DatagramPacket.cpp

SocketMulticast.o: ../Libraries/SocketMulticast.cpp ../Libraries/SocketMulticast.h
	g++ -c ../Libraries/SocketMulticast.cpp

Emitter: DatagramPacket.o SocketMulticast.o Emitter.cpp
	g++ DatagramPacket.o SocketMulticast.o Emitter.cpp -o Emitter -I../Libraries

Receiver: DatagramPacket.o SocketMulticast.o Receiver.cpp
	g++ DatagramPacket.o SocketMulticast.o Receiver.cpp -o Receiver -I../Libraries

Emitter2: DatagramPacket.o SocketMulticast.o Emitter2.cpp
	g++ DatagramPacket.o SocketMulticast.o Emitter2.cpp -o Emitter2 -I../Libraries

Receiver2: DatagramPacket.o SocketMulticast.o Receiver2.cpp
	g++ DatagramPacket.o SocketMulticast.o Receiver2.cpp -o Receiver2 -I../Libraries

clean:
	rm -rf *.o Emitter Receiver Emitter2 Receiver2