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
	char cadena[4];
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
        cadena[0] = ' ';
        for(int i = 1; i < 4; i++)
            cadena[i] = random('A', 'Z');
        write(destino, cadena, 4);       
    }
    char aux = '\0';
    write(destino, &aux, 1);
    fsync(destino);
    close(destino);
}
