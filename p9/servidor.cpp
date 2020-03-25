#include "SocketDatagrama.h"

int main(int argc, char * argv[]) {
    //Servidor
    SocketDatagrama cliente(7200);
    PaqueteDatagrama pack(2*sizeof(int));

    int num[1];
    int res,x,y;
    while(1) {
        cliente.recibe(pack);
        printf("%s\n","Recibido de:" );
        printf("Direccion :%s\n Puerto:%d\n", pack.obtieneDireccion(), pack.obtienePuerto());

        memcpy(&x, pack.obtieneDatos(), sizeof(int));
        memcpy(&y, pack.obtieneDatos()+(sizeof(int)), sizeof(int));
        res = x + y ;
        printf("%d + %d = %d\n", x, y, res);
        num[0]=res;

        PaqueteDatagrama packR(sizeof(int));
        packR.inicializaPuerto(pack.obtienePuerto());
        packR.inicializaIp(pack.obtieneDireccion());
        packR.inicializaDatos((char *) num);
        
        cliente.envia(packR);
        printf("%s\n","Enviando mensaje...." );
        
        printf("%s\n", "Caso existo, se ha enviado el resultado");

    }

    return 0;
}

