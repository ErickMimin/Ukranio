#include <iostream>
#include <string>
using namespace std;

int main() {
   string cadena("ESCOM");
   cout << cadena[6] << endl;
   //cout << cadena.at(6) << endl;
   return 0;
   /*terminate called after throwing an instance of 'std::out_of_range'
   what():  basic_string::at: __n (which is 6) >= this->size() (which is 5)
   Abortado (`core' generado)  */

}
