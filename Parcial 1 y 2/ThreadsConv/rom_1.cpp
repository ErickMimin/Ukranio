#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
char buffer[BUFSIZ];

char random(char min, char max) {
	return min + rand() % (max-min +1);
}

int main(int argc, char *argv[]){
    size_t N = 26 * 26 * 26 * 100;
    char aux;
    int destino;
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
        exit(0);
    }
    //cout << "Introduce texto para guardar en el archivo y ENTER para terminar. Longitud máxima de caracteres = " << BUFSIZ << endl;
    
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    for( int n = 0; n < N; n++){
        aux = ' ';
        write(destino, &aux, 1);
        for(int i = 1; i < 4; i++){
            aux = random('A', 'Z');
            write(destino, &aux, 1);
        }        
    }
    aux = '\0';
    write(destino, &aux, 1);
    //getline(cin, linea);
    //strcpy(buffer, linea.c_str( ));
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    fsync(destino);
    close(destino);
}
