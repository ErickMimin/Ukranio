
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
	char* cadenon = NULL;
    size_t tamanio = 0;
    int destino;
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
        exit(0);
    }
    //cout << "Introduce texto para guardar en el archivo y ENTER para terminar. Longitud máxima de caracteres = " << BUFSIZ << endl;
    
    for( int n = 0; n < N; n++){
        tamanio += 4;
        cadenon= (char*)realloc(cadenon, tamanio);
        cadenon[tamanio - 4] = ' ';
        for(int i = 1; i < 4; i++)
            cadenon[tamanio - i] = random('A', 'Z');
        
    }
    cadenon= (char*)realloc(cadenon, ++tamanio);
    cadenon[tamanio] = '\0';
    //getline(cin, linea);
    //strcpy(buffer, linea.c_str( ));
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    write(destino, cadenon, tamanio);
    fsync(destino);
    close(destino);
}