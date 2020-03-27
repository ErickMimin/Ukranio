#include <iostream>
#include <string>
#include "Response.h"

using namespace std;

int main(int argc, char* argv[]){
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        cerr << "ERROR: No se introdujo puerto" << endl;
        exit(1);
    }

    Response r((uint16_t) atoi(argv[1]));
    cout << "Servidor iniciado...\n";
    while(true){
        Menssage *msg = r.getRequest();
        int* nums = (int*)msg->arguments;
        cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;
        cout << " operation ID = " << msg->operationId << endl;
        cout << " sizeof(args) = " << msg->length << endl;

        if (msg->operationId == Menssage::allowedOperations::sum){
            cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
            int suma = nums[0] + nums[1];
            r.sendResponse((char*)&suma, sizeof(suma));
        }
        cout << "\n";
    }
    return 0;
}
