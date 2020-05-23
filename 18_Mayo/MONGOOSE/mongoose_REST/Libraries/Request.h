#include "DatagramSocket.h"
#include "Menssage.h"

#ifndef REQUEST_H
#define REQUEST_H

int random(int min, int max);

class Request {
    public:
        Request();
        char* doOperation(const std::string addr, uint16_t iport, Menssage::allowedOperations operation, char *arguments, size_t len, size_t &len_reply);
        char* doOperationBroadcast(const std::string addr, uint16_t iport, Menssage::allowedOperations operation, char *arguments, size_t len, size_t &len_reply);
    private:
        int cont = 0;
};

#endif
