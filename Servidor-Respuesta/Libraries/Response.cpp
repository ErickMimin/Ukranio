#include "Response.h"
#include <string.h>
#include <iostream>

Response::Response(int iport){
	localSocket = new DatagramSocket(iport);
}

Menssage* Response::getRequest() {
	Menssage *msg = new Menssage();
	DatagramPacket pq((char*)msg, sizeof(Menssage));
	localSocket->receive(pq);

	if(msg->requestId == cont){
		cont++;
		requestId = msg->requestId;
	}else
		msg->operationId = Menssage::allowedOperations::verification;

	address = pq.getAddress();
	port = pq.getPort();
	operation = msg->operationId;
	return msg;
}

void Response::sendResponse(const char *arguments, size_t len){
	Menssage *msg = new Menssage();
	msg->messageType = Menssage::kindMessages::response;
	msg->operationId = operation;
	msg->requestId = requestId;
	memcpy(msg->arguments, arguments, len);
	msg->length = len;

	DatagramPacket paquete((char*)msg, sizeof(Menssage), address, port);
	localSocket->send(paquete);
}
