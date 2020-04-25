#include "SocketMulticast.h"
#include <bits/stdc++.h>
using namespace std;

/* Generamos semilla */
std::mt19937_64 seed(std::chrono::steady_clock::now().time_since_epoch().count());

int random(int min, int max){
    return std::uniform_int_distribution<int>(min, max)(seed);
}

/* 
    Programa Emisor
    Manda un mensaje a un grupo multicast
    Recibe:
    - IP multicast
    - Puerto
    - Parametro TTL
    - Numero de depositas
 */
int main(int argc, char* argv[]){
    int n = atoi(argv[4]), deposit;
    DatagramPacket packet((char*) &deposit, sizeof(int), argv[1], atoi(argv[2]));
    SocketMulticast ms;
    for(int i = 0; i < n; i++){
        deposit = random(1, 9);
        try{
            ms.reliableSend(packet, atoi(argv[3]), 3);
        }catch(string err){
            cout << err << endl;
        }
    }
    
}