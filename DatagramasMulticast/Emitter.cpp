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
    - Mensaje
 */
int main(int argc, char* argv[]){
    try {
        string msg(argv[4]);
        SocketMulticast ms;
        DatagramPacket packet(argv[4], strlen(argv[4]) + 1, argv[1], atoi(argv[2]));
        ms.send(packet, atoi(argv[3]));
    } catch (string err){
        cout << err << endl;
    }
}