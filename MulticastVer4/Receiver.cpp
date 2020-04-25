#include "SocketMulticast.h"
#include <bits/stdc++.h>
using namespace std;

/* 
    Programa Receptor
    Manda un mensaje a un grupo multicast
    Recibe:
    - IP multicast
    - Puerto
 */
int main(int argc, char* argv[]) {
    try {
        char msg[100];
        SocketMulticast ms(atoi(argv[2]));
        ms.joinGroup(argv[1]);
        DatagramPacket packet(msg, sizeof(msg));
        //ms.receiveTimeout(packet, 3, 0);
        ms.receive(packet);
        cout << "Message from " << packet.getAddress() << ':' << packet.getPort() << endl;
        cout << msg << endl;
    }catch (string err) {
        cout << err << endl;
    }
}