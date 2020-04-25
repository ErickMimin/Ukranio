#include "SocketMulticast.h"
#include <bits/stdc++.h>
using namespace std;

/* 
    Programa Emisor
    Manda un mensaje a un grupo multicast
    Recibe:
    - IP multicast
    - Puerto
    - Parametro TTL
    - Numero 1
    - Numero 2
 */
int main(int argc, char* argv[]){
    try {
        int num[1];
        int req[2];
        req[0] = atoi(argv[4]);
        req[1] = atoi(argv[5]);
        string msg(argv[4]);
        SocketMulticast ms;
        DatagramPacket packet((char*)req, 2 * sizeof(int), argv[1], atoi(argv[2]));
        ms.send(packet, atoi(argv[3]));
        DatagramPacket responsePacket((char*)num, sizeof(int));
        while(true){
            ms.receiveTimeout(responsePacket, 10, 0);
            cout << "Message from " << responsePacket.getAddress() << ":" << responsePacket.getPort() << endl;
            cout << "Result: " << (int)*responsePacket.getData() << endl;
        }
    } catch (string err){
        cout << err << endl;
    }
}