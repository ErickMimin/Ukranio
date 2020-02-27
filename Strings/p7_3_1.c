#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
char aleat(char min, char max){
	return min + rand() % (max-min + 1);
}

int main(void) {
	srand(time(NULL));
	int i, j;
	int aparece = 0;
	char *cadenota = NULL;
	int n = 26*26*26*4;
	int tamanio = 0;
	
	for( i = 0; i < n; i++) {
		tamanio = tamanio + 4; //Añadimos 4 a lo que sera tamaño de cadena gigante
		cadenota = (char*) realloc(cadenota,tamanio); //Modificamos tamaño de cadena
		cadenota[tamanio - 4] = ' '; //Cada 4 posiciones iremos poniendo espacio
		for(j = 1; j < 4; j++) { //Añadiremos de 3 en 3, letras random dando espacio
				cadenota[tamanio-j] = aleat('A', 'Z'); //Copia elementos random a cadenota, hacemos la resta para no tener errores de posición
		}
	}
	
	char* pos = strstr(cadenota, "IPN"); //Apuntador a primera ocurrencia de "IPN" en la cadena gigante 	

	while(pos) {	//Mientras haya apariciones, aumentamos "aparece" y recorremos en 1 posicion para volver a buscar.
		aparece++;
		pos = strstr(pos+1, "IPN");
	}

	printf("\nLa cadena aparece %d veces\n", aparece);

	return 0;
}
