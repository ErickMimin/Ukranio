#include "SocketMulticast.h"
#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;

/* 
    Programa Emisor
    Manda un mensaje a un grupo multicast
    Recibe:
    - IP multicast
    - Puerto
    - Parametro TTL
    - Numero de depositas
 */


/* Generamos semilla */
std::mt19937_64 seed(std::chrono::steady_clock::now().time_since_epoch().count());

int random(int min, int max){
    return std::uniform_int_distribution<int>(min, max)(seed);
}

int main(int argc, char* argv[]){
    int deposit = random(1, 9);
    DatagramPacket packet((char*)&deposit, sizeof(int), argv[1], atoi(argv[2]));

    try {
        string msg(argv[4]);
        SocketMulticast ms;
        ms.send(packet, atoi(argv[3]));
    } catch (string err){
        cout << err << endl;
    }
}