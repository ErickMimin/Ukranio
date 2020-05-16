#include <iostream>
#include <string>
#include <map>
#include <fcntl.h>
#include <unistd.h>
#include "Response.h"
#include <sys/time.h>
#include <string.h>
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector
#include "arbol.h"
#include "Request.h"
using namespace std;


int main(int argc, char* argv[]){
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        //cerr << "ERROR: No name file" << endl;
        exit(1);
    }
    struct TrieNode *root = getNode(); 
    Response r(atoi(argv[2]));
    Request rNTP;
	size_t len_response;
    int destino = open(argv[1], O_TRUNC|O_WRONLY|O_CREAT, 0666);

    while(true){
        Menssage *msg = r.getRequest();
        /*cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;*/
        if(msg->operationId == Menssage::allowedOperations::send){
            struct timeval *tv;

            /* Sincronizamos relojes */
            tv = (struct timeval*) rNTP.doOperation(argv[3], atoi(argv[4]), Menssage::allowedOperations::send, NULL, 0, len_response);
            if(tv == NULL)
                gettimeofday(tv, NULL);

            char buffer[16];
            snprintf(buffer,16,"%ldu%ld", tv->tv_sec,tv->tv_usec); // se concatena los segundos con microsegundos
            
            Registro *regis = (Registro*)msg->arguments;

            if (search(root, string(regis->celular))){
                std::cout << "Numero Repetido!\n";
                snprintf(buffer,16,"%du%d", 0,0); // se concatena los segundos con microsegundo
                r.sendResponse(buffer, strlen(buffer)); 
            }
            else {
                insert(root, string(regis->celular));
                std::cout << "Numero NO Repetido.\n";
                memcpy(regis->sec, buffer, 16);
                /*cout << regis->celular << endl;
                cout << regis->CURP << endl;
                cout << regis->partido << endl;
                cout << regis->sec << endl; */
                int response = write(destino, regis, sizeof(Registro));
                r.sendResponse(buffer, strlen(buffer));
            } 
        } 
    }
    //cout << "Servivor apagandose..." << endl;
    return 0;
}

//|O_APPEND|O_CREAT|O_TRUNC
