#include <iostream>
#include <string>
#include <map>
#include <fcntl.h>
#include <unistd.h>
#include "Response.h"

using namespace std;

int main(int argc, char* argv[]){
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        cerr << "ERROR: No name file" << endl;
        exit(1);
    }

    Response r(3000);
    map<string, int> nbd;

    cout << "Servidor iniciado..." << endl;

    while(true){
        Menssage *msg = r.getRequest();
        //int* nums = (int*)msg->arguments;

        cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;
        cout << " operation ID = " << msg->operationId << endl;
        cout << " sizeof(args) = " << msg->length << endl;

        if(msg->operationId == Menssage::allowedOperations::send){
            int destino = open(argv[1], O_WRONLY|O_APPEND, 0666);
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
