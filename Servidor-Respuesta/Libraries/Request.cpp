#include "Request.h"
#include <chrono>
#include <random>
#include <stdlib.h>
#include <string.h>

/* Generamos semilla */
std::mt19937_64 seed(std::chrono::steady_clock::now().time_since_epoch().count());

int random(int min, int max){
    return std::uniform_int_distribution<int>(min, max)(seed);
}

char* Request::doOperation(const std::string addr, uint16_t iport, Menssage::allowedOperations operation, char *arguments, size_t len, size_t &len_reply){
    Menssage *msg = new Menssage();
    msg->messageType = Menssage::kindMessages::request;
    msg->requestId = random(1, 1 << 30);
    msg->operationId = operation;
    memcpy(msg->arguments, arguments, len);
    msg->length = len;

    DatagramPacket pq((char*)msg, sizeof(Menssage), addr, iport);
    DatagramSocket sock;
    //sock.send(pq);

    Menssage *msg2 = new Menssage();
    DatagramPacket pqresp((char*)msg2, sizeof(Menssage));
    int i=0;
    while(i<7){
        sock.send(pq);
        sock.receiveTimeout(pqresp, 2, 500000);
        ++i;
    }

    if(i==7){
        printf(" El servidor no está disponible\n");
        exit(-1);
    }
    //sock.receive(pqresp);
    len_reply = msg2->length;
    return msg2->arguments;
}

Request::Request(){}
