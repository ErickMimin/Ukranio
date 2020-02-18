#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
using namespace std;

char random(char min, char max) {
	return min + rand() % (max-min +1);
}

int main(int argc, char* argv[]){
	srand (time(NULL));
	int aparece = 0;
	size_t N = 26*26*26 * 1000;	
	string cadenota;
	char* cadenon = NULL;

	if(atoi(argv[1]) == 1){
		/*Por probabilidad, una permutación es la variación de la posición de los elementos de un conjunto ordenado,
		si importa el orden. Por ello, en este caso tendriamos que n debe ser igual a  26P3 para poder tener una 
		aparicion, teoricamente. Ese valor es 15600 */
		for( int n = 0; n < N  ; n++){
			cadenota += ' ';
			for(int i = 0; i < 3; i++)
				cadenota += random('A', 'Z');		
		}
		//cout << cadenota;	
		size_t pos = cadenota.find("IPN");
		while( pos != string::npos){   //npos es una constante con el valor maximo que puede tener un size_t
			aparece++;
			pos = cadenota.find("IPN", pos + 1);
		}
	}else{
		size_t tamanio = 0;
		for( int n = 0; n < N  ; n++){
			tamanio += 4;
			cadenon= (char*)realloc(cadenon, tamanio);
			cadenon[tamanio - 4] = ' ';
			for(int i = 1; i < 4; i++)
				cadenon[tamanio - i] = random('A', 'Z');
			
		}
		for(int i = 0; i < tamanio; i += 4){
			//cout << cadenon[i + 1] << cadenon[i + 2] << cadenon[i + 3] << endl;
			if(cadenon[i + 1] == 'I' && cadenon[i + 2] == 'P'  && cadenon[i + 3] == 'N')
				aparece++;
		}
		free(cadenon);
	}

	cout << "La palabra buscada aparece " << aparece << " veces" << endl;	
	return 0;
}
