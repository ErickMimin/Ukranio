#include <iostream>
#include <string>
using namespace std;

int main() {
   int z;
   string line;
   cin >> z;
   getline(cin, line);
  // cin lee un token y deja un salto de linea esperando en el buffer y getline
  // lee hasta el salto de linea por lo que estariamos leyendo un string vacio

   return 0;
}
