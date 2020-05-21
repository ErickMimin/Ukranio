#include "DatagramSocket.h"
#include "Menssage.h"

#ifndef RESPONSE_H_
#define RESPONSE_H_
class Response{
    public:
        Response(int pl);
        struct Menssage *getRequest(void);
        struct Menssage* getRequestNoValidation();
        void sendResponse(const char*, size_t);
        std::string address;
		uint16_t port;
		unsigned int requestId;
    private:
        DatagramSocket *localSocket;
		Menssage::allowedOperations operation;
        int cont = 0;
};
#endif