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
        int num[2], result;
        SocketMulticast ms(atoi(argv[2]));
        ms.joinGroup(argv[1]);
        DatagramPacket packet((char*)num, 2 * sizeof(int));
        //ms.receiveTimeout(packet, 3, 0);
        ms.receive(packet);
        result = num[0] + num[1];
        cout << "Message from " << packet.getAddress() << ':' << packet.getPort() << endl;
        cout << num[0] << " + " << num[1] << " = " << result << endl;
        /* Devolvemos el resultado */
        DatagramPacket resultPacket((char*)&result, sizeof(int), packet.getAddress(), packet.getPort());
        ms.send(resultPacket, 10);
    }catch (string err) {
        cout << err << endl;
    }
}