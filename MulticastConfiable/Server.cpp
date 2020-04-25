#include "SocketMulticast.h"
#include <bits/stdc++.h>
using namespace std;

/* 
    Programa Receptor
    Manda un mensaje a un grupo multicast
    Recibe:
    - IP multicast
    - Puerto
    - Parametro TTL
 */
int main(int argc, char* argv[]) {
    try {
        int cont = 0;
        int deposit;
        SocketMulticast ms(atoi(argv[2]));
        ms.joinGroup(argv[1]);
        DatagramPacket packet((char*)&deposit, sizeof(int));
        //ms.receiveTimeout(packet, 3, 0);
        while (true){
            ms.realiableReceive(packet, atoi(argv[3]));
            cont += deposit;
            cout << "Message from " << packet.getAddress() << ':' << packet.getPort() << endl;
            cout << "Recibimos " << deposit << ", Saldo actual " << cont << endl;
        }        
    }catch (string err) {
        cout << err << endl;
    }
}