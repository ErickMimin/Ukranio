#include <iostream>
#include <string>
#include <map>
#include <fcntl.h>
#include <unistd.h>
#include "Response.h"
#include <sys/time.h>

using namespace std;

struct timeval {
time_t tv_sec; /* segundos */
suseconds_t tv_usec; /* microsegundos */
};




int main(int argc, char* argv[]){
    struct timeval uniqueID;
    int gettimeofday(*uniqueID, NULL);
    
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        cerr << "ERROR: No name file" << endl;
        exit(1);
    }

    Response r(3000);
    map<string, int> nbd;

    cout << "Servidor iniciado..." << endl;
    int destino = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);

    while(true){
        Menssage *msg = r.getRequest();
        //int* nums = (int*)msg->arguments;
        destino = open(argv[1], O_APPEND|O_WRONLY, 0666);

        cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;

        if(msg->operationId == Menssage::allowedOperations::send){
            Registro *regis = (Registro*)msg->arguments;
            cout << regis->celular << endl;
            cout << regis->CURP << endl;
            cout << regis->partido << endl;
            int response = write(destino, regis, sizeof(Registro));
            r.sendResponse((char*)&response, sizeof(int));
            close(destino);
        }
            
        
    }
    cout << "Servivor apagandose..." << endl;
    return 0;
}

//|O_APPEND|O_CREAT|O_TRUNC
