#include <iostream>
#include <string>
#include <map>
#include "Response.h"

using namespace std;

int main(int argc, char* argv[]){
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        cerr << "ERROR: No se introdujo puerto" << endl;
        exit(1);
    }

    Response r((uint16_t) atoi(argv[1]));
    map<string, int> nbd;

    cout << "Servidor iniciado..." << endl;

    while(true){
        Menssage *msg = r.getRequest();
        int* nums = (int*)msg->arguments;

        cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;
        cout << " operation ID = " << msg->operationId << endl;
        cout << " sizeof(args) = " << msg->length << endl;

        if(msg->operationId == Menssage::allowedOperations::sum){
            int suma = nums[0] + nums[1];
            r.sendResponse((char*)&suma, sizeof(suma));
        }else if(msg->operationId == Menssage::allowedOperations::transfer){
            if(nbd.find(r.address) != nbd.end())
				nbd.insert(pair<string, int>(r.address, 0));
			nbd[r.address] += *nums;				
			r.sendResponse((char*)&nbd[r.address], sizeof(int));
        }else if(msg->operationId == Menssage::allowedOperations::verification){
			r.sendResponse((char*)&nbd[r.address], sizeof(int));
        }
    }
    cout << "Servivor apagandose..." << endl;
    return 0;
}
