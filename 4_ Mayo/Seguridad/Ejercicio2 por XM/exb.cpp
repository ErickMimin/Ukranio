// binary_search example
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector
#include <string.h> 

int main () {
  int myints[] = {1,2,3,4,5,6,7,8,9};
  //std::vector<int> v(myints,myints+5);// 1 2 3 4 5 4 3 2 1
  std::string k ="abcde";
  std::vector<std::string> v;

  v.push_back ("hola");
  v.push_back ("algorithm");
  v.push_back ("perro");


  // using default comparison:
  std::sort (v.begin(), v.end());

  std::cout << "looking for a 3... ";
  if (std::binary_search (v.begin(), v.end(), "hola"))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}