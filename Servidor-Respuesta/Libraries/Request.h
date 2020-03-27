#include "DatagramSocket.h"
#include "Menssage.h"

#ifndef REQUEST_H
#define REQUEST_H

class Request {
    public:
        Request();
        char* doOperation(const std::string addr, uint16_t iport, Menssage::allowedOperations operation, char *arguments, size_t len, size_t &len_reply);
};

#endif
